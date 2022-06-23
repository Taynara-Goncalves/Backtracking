// combinasoma.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

//Imprima todas as combinações de números de 1 a `n` com soma `n`
//Dado um inteiro positivo n, imprima todas as combinações de números entre 1 e n tendo soma n.

#include <iostream>
#include <vector>

using namespace std;

// Função para imprimir o conteúdo de um determinado array
void printCombination(vector<int> const& out)
{
    for (int i : out) {
        cout << i << " ";
    }
    cout << endl;
}

// Função recursiva para imprimir todas as combinações de números
// de `i` para `n` tendo a soma `n`
void printCombinations(int i, int n, vector<int>& out)
{
    // se a soma se tornar `n`, imprime a combinação
    if (n == 0) {
        printCombination(out);
    }

    // começa do elemento anterior na combinação até `n`
    for (int j = i; j <= n; j++)
    {
        // inclui o elemento atual da combinação
        out.push_back(j);

        //recorre com uma soma reduzida
        printCombinations(j, n - j, out);

        // backtrack: remove o elemento atual da combinação
        out.pop_back();
    }
}

int main()
{
    int n = 5;

    vector<int> out;

    // retorna todas as combinações de números de 1 a `n` com soma `n`
    printCombinations(1, n, out);

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
