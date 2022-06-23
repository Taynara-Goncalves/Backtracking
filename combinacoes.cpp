// combinacoes.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

//Encontre todas as combinações de elementos que satisfaçam as restrições dadas
//Dado um número positivo n, encontre todas as combinações de 2×n elementos tais que cada 
//elemento de 1 a n aparece exatamente duas vezes e a distância entre suas duas aparições é 
//exatamente igual ao valor do elemento.


#include <iostream>
#include <vector>
using namespace std;

// Encontra todas as combinações que satisfazem as restrições fornecidas
void findAllCombinations(vector<int>& arr, int x, int n)
{
    // se todos os elementos estiverem preenchidos, imprime a solução
    if (x > n)
    {
        for (int i : arr) {
            cout << i << " ";
        }
        cout << endl;

        return;
    }

    // tenta todas as combinações possíveis para o elemento `x`
    for (int i = 0; i < 2 * n; i++)
    {
        // se as posições `i` e `i+x+1` não estiverem ocupadas no vetor
        if (arr[i] == -1 && (i + x + 1) < 2 * n &&
            arr[i + x + 1] == -1)
        {
            // coloca `x` na posição `i` e `i+x+1`
            arr[i] = x;
            arr[i + x + 1] = x;

            //recorre para o próximo elemento
            findAllCombinations(arr, x + 1, n);

            // retroceder (remover `x` da posição `i` e `i+x+1`)
            arr[i] = -1;
            arr[i + x + 1] = -1;
        }
    }
}

int main()
{
    // número dado
    int n = 7;

    // cria um vetor com o dobro do tamanho de um determinado número com
    // todos os seus elementos inicializados por -1
    vector<int> arr(2 * n, -1);

    //começa do elemento 1
    int x = 1;
    findAllCombinations(arr, x, n);

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
