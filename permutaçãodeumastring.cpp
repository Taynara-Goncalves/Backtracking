// permutaçãodeumastring.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

//Por exemplo, a cadeia ABC tem 6 permutações, ou seja, ABC, ACB, BAC, BCA, CBA, CAB.

#include <iostream>
using namespace std;

// Função para encontrar todas as permutações de uma determinada string `str[i…n-1]`
// contendo todos os caracteres distintos
void permutations(string str, int i, int n)
{
    // condição básica
    if (i == n - 1)
    {
        cout << str << endl;
        return;
    }

    // processa cada caractere da string restante
    for (int j = i; j < n; j++)
    {
        // troca o caractere no índice `i` com o caractere atual
        swap(str[i], str[j]);        // STL `swap()` usado

        // retorna para a substring `str[i+1, n-1]`
        permutations(str, i + 1, n);

        // backtrack (restaura a string ao seu estado original)
        swap(str[i], str[j]);
    }
}

int main()
{
    string str = "ABC";

    permutations(str, 0, str.length());

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
