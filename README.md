# Busca Paralela pelo Maior Número em C++ com OpenMP

**Autor**: Yago Phellipe Matos Lopes  
**Curso**: Ciência da Computação  

---

## Sobre o Projeto

Este projeto implementa a busca pelo maior número em uma lista de inteiros usando duas abordagens: **serial** e **paralela**. A solução paralela utiliza a biblioteca OpenMP para dividir o trabalho entre múltiplos threads, garantindo eficiência em listas muito grandes. O objetivo é comparar o desempenho das duas abordagens e validar os resultados.

---

## Funcionalidades

- **Busca Serial**:
  - Realiza a busca do maior número de forma sequencial.
  - Simples e eficiente para listas menores, mas com limitações de desempenho para listas grandes.

- **Busca Paralela**:
  - Utiliza OpenMP para dividir a busca pelo maior número entre diferentes threads.
  - Cada thread calcula o maior número em uma parte da lista, e os resultados são combinados para encontrar o maior número global.
  - Permite testar o desempenho com diferentes números de threads.

---

## Como Funciona?

1. **Inicialização da Lista**:
   - Uma lista de números inteiros é gerada aleatoriamente com valores entre 0 e 999.
   - O tamanho da lista é configurado para **100 milhões de elementos**, permitindo a análise de desempenho.

2. **Busca pelo Maior Número**:
   - **Serial**:
     - A função `maior_serial` percorre toda a lista e atualiza o maior número encontrado.
   - **Paralela**:
     - A função `maior_paralelo` divide a lista em partes iguais, uma para cada thread.
     - Cada thread calcula o maior número em sua parte, armazenando os resultados em um vetor de máximos parciais.
     - Os máximos parciais são combinados para encontrar o maior número global.

3. **Validação**:
   - Após realizar as buscas serial e paralela, os resultados são comparados para garantir que ambos retornam o mesmo valor.

4. **Medição de Desempenho**:
   - O tempo de execução é medido para as abordagens serial e paralela.
   - A busca paralela é testada com diferentes números de threads (2, 4 e 8) para analisar o impacto do paralelismo.

---
