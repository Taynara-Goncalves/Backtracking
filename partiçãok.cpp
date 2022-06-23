// partiçãok.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

//Problema de partição K | Imprimindo todas as partições
//No problema de k - partição, precisamos particionar um array de 
//inteiros positivos em k subconjuntos disjuntos que todos têm uma soma igual e 
//cobrem completamente o conjunto.


#include <iostream>
#include <numeric>

using namespace std;

// Função para verificar se todos os subconjuntos estão preenchidos ou não
bool checkSum(int sumLeft[], int k)
{
    int r = true;
    for (int i = 0; i < k; i++)
    {
        if (sumLeft[i] != 0) {
            r = false;
        }
    }

    return r;
}

// Função auxiliar para resolver o problema da partição `k`.
// Retorna true se existirem subconjuntos `k` com a soma dada
bool subsetSum(int S[], int n, int sumLeft[], int A[], int k)
{
    // retorna true se um subconjunto for encontrado
    if (checkSum(sumLeft, k)) {
        return true;
    }

    // caso base: nenhum item restante
    if (n < 0) {
        return false;
    }

    bool result = false;

    // considera o item atual `S[n]` e explora todas as possibilidades
    // usando retrocesso
    for (int i = 0; i < k; i++)
    {
        if (!result && (sumLeft[i] - S[n]) >= 0)
        {
            // marca o subconjunto do elemento atual
            A[n] = i + 1;

            // adiciona o item atual ao i'ésimo subconjunto
            sumLeft[i] = sumLeft[i] - S[n];

            //recorre para os itens restantes
            result = subsetSum(S, n - 1, sumLeft, A, k);

            // backtrack: remove o item atual do i'ésimo subconjunto
            sumLeft[i] = sumLeft[i] + S[n];
        }
    }

    // retorna true se obtivermos uma solução
    return result;
}

// Função para resolver o problema de k–partição. Ele imprime os subconjuntos se
// set `S[0…n-1]` pode ser dividido em `k` subconjuntos com soma igual
void partition(int S[], int n, int k)
{
    // caso base
    if (n < k)
    {
        cout << "k-partition of set S is not possible";
        return;
    }

    // obtém a soma de todos os elementos do conjunto
    int sum = accumulate(S, S + n, 0);

    int A[n], sumLeft[k];

    // cria um array de tamanho `k` para cada subconjunto e inicializa-o
    // pela soma esperada, ou seja, `sum/k`
    for (int i = 0; i < k; i++) {
        sumLeft[i] = sum / k;
    }

    // retorna true se a soma for divisível por `k` e set `S` pode
    // ser dividido em `k` subconjuntos com soma igual
    bool result = !(sum % k) && subsetSum(S, n - 1, sumLeft, A, k);

    if (!result)
    {
        cout << "k-partition of set S is not possible";
        return;
    }

    // imprime todas as k–partições
    for (int i = 0; i < k; i++)
    {
        cout << "Partition " << i << " is ";
        for (int j = 0; j < n; j++)
        {
            if (A[j] == i + 1) {
                cout << S[j] << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    // Entrada: um conjunto de inteiros
    int S[] = { 7, 3, 5, 12, 2, 1, 5, 3, 8, 4, 6, 4 };

    // número total de itens em `S`
    int n = sizeof(S) / sizeof(S[0]);
    int k = 5;

    partition(S, n, k);

    return 0;
}


// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
