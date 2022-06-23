// combinacaoem3.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

//Imprima todos os trigêmeos em uma matriz com uma soma menor ou igual a um determinado número
//Dado um array inteiro não classificado, imprima todos os trigêmeos nele com soma menor ou igual 
//a um determinado número.

#include <iostream>
#include <algorithm>

using namespace std;

// Função para imprimir todos os trigêmeos distintos em um array com uma soma
// menor ou igual a um determinado número
void printAllTriplets(int nums[], int n, int sum)
{
    // ordena o array em ordem crescente
    sort(nums, nums + n);

    // verifica se a trinca é formada por `nums[i]` e um par de
    // subarray `nums[i+1…n)`
    for (int i = 0; i <= n - 3; i++)
    {
        // mantém dois índices apontando para endpoints do
        // subarray `nums[i+1…n)`
        int low = i + 1, high = n - 1;

        // faz se `low` for menor que `high`
        while (low < high)
        {
            // diminui `high` se o total for maior que a soma restante
            if (nums[i] + nums[low] + nums[high] > sum) {
                high--;
            }

            else {
                // se o total for menor ou igual à soma restante,
                // imprime todos os trigêmeos
                for (int x = low + 1; x <= high; x++) {
                    cout << "(" << nums[i] << ", " << nums[low] << ", " << nums[x] << ")";
                }

                low++;    // incrementa baixo
            }
        }
    }
}

int main()
{
    int nums[] = { 2, 7, 4, 9, 5, 1, 3 };
    int sum = 10;

    int n = sizeof(nums) / sizeof(nums[0]);

    printAllTriplets(nums, n, sum);

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
