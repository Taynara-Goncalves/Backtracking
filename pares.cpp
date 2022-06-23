// pares.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//
//Encontre todos os números de n dígitos com igual soma de dígitos em índices pares e ímpares
//Encontre todos os números de n dígitos com uma soma igual de dígitos em índices pares e ímpares, 
//onde n varia de 2 para 9.


#include <iostream>
using namespace std;

// Função para encontrar todos os números de n dígitos com uma soma igual de dígitos em pares
// e índice ímpar de forma ascendente
void findNdigitNums(string result, int n, int diff)
{
    // se o número for menor que n–dígito
    if (n)
    {
        char ch = '0';
        // caso especial: o número não pode começar de 0
        if (result == "") {
            ch = '1';
        }

        // considera cada dígito válido e coloca no atual
        // indexa e retorna para o próximo índice
        while (ch <= '9')
        {
            int absdiff;

            // atualiza a diferença entre dígitos pares e ímpares
            if ((n & 1) != 0)
            {
                // adiciona valor a `diff` se o dígito for ímpar
                absdiff = diff + (ch - '0');
            }
            else {
                // subtrai um valor de `diff` se par
                absdiff = diff - (ch - '0');
            }

            findNdigitNums(result + ch, n - 1, absdiff);
            ch++;
        }
    }
    // se o número se tornar n-dígito com uma soma igual de pares e ímpares
    // dígitos, imprime
    else if (n == 0 && abs(diff) == 0) {
        cout << result << " ";
    }
}

int main()
{
    int n = 3;        // n-dígito
    string result;

    findNdigitNums(result, n, 0);

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
