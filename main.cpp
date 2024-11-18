#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <omp.h>

// Função que inicializa uma lista com números inteiros aleatórios
void inicializar_lista(std::vector<int>& lista, int tamanho) {
    srand(static_cast<unsigned>(time(nullptr)));
    for (int i = 0; i < tamanho; i++) {
        lista.push_back(rand() % 1000);
    }
}

// Função para encontrar o maior número de forma paralela
int maior_paralelo(const std::vector<int>& lista, int num_threads) {
    std::vector<int> maximos_parciais(num_threads, INT_MIN); // Vetor para armazenar máximos parciais

    omp_set_num_threads(num_threads);

    // Cada thread calcula o maior de sua parte do vetor
    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        int tamanho = lista.size();
        int inicio = (tamanho / num_threads) * thread_id;
        int fim = (thread_id == num_threads - 1) ? tamanho : inicio + (tamanho / num_threads);

        for (int i = inicio; i < fim; i++) {
            if (lista[i] > maximos_parciais[thread_id]) {
                maximos_parciais[thread_id] = lista[i];
            }
        }
    }

    // Combina os máximos parciais para encontrar o maior global
    int maior_global = INT_MIN;
    for (int max : maximos_parciais) {
        if (max > maior_global) {
            maior_global = max;
        }
    }

    return maior_global;
}

// Função para encontrar o maior número de forma serial
int maior_serial(const std::vector<int>& lista) {
    int maior = INT_MIN;
    for (int valor : lista) {
        if (valor > maior) {
            maior = valor;
        }
    }
    return maior;
}

int main() {

    int tamanho = 100000000;
    std::vector<int> lista;
    inicializar_lista(lista, tamanho);

    // Busca serial
    double inicio_serial = omp_get_wtime();
    int resultado_serial = maior_serial(lista);
    double tempo_serial = omp_get_wtime() - inicio_serial;
    std::cout << "Maior Serial: " << resultado_serial << ", Tempo Serial: " << tempo_serial << " segundos" << std::endl;

    // Busca paralela com diferentes números de threads
    for (int num_threads = 2; num_threads <= 8; num_threads *= 2) {
        double inicio_paralelo = omp_get_wtime();
        int resultado_paralelo = maior_paralelo(lista, num_threads);
        double tempo_paralelo = omp_get_wtime() - inicio_paralelo;

        if (resultado_serial != resultado_paralelo) {
            std::cerr << "Erro: Resultados não coincidem!" << std::endl;
            return -1;
        }

        std::cout << "Maior Paralelo com " << num_threads << " threads: " << resultado_paralelo
                  << ", Tempo Paralelo: " << tempo_paralelo << " segundos" << std::endl;
    }

    return 0;
}
