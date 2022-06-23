// rotascurtas.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

//Imprima todas as rotas mais curtas em uma grade retangular
//Dado um M × N grade retangular, imprima todas as rotas na grade que começam na primeira célula(0, 0) 
//e termina na última célula(M - 1, N - 1).Podemos mover para baixo ou para a direita ou diagonalmente(baixo - direita), 
//mas não para cima ou para a esquerda.

#include <iostream>
#include <vector>

using namespace std;

// Função recursiva para obter todas as rotas em uma grade retangular
// que começa na célula (i, j) e termina na última célula (M-1, N-1).
void printPaths(vector<vector<int>> const& mat, vector<int>& route, int i, int j)
{
    // caso base
    if (mat.size() == 0) {
        return;
    }

    // matriz `M × N`
    int M = mat.size();
    int N = mat[0].size();

    // se a última célula for alcançada
    if (i == M - 1 && j == N - 1)
    {
        // imprime a rota atual
        for (int i : route) {
            cout << i << ", ";
        }
        cout << mat[i][j] << endl;
        return;
    }

    // inclui a célula atual na rota
    route.push_back(mat[i][j]);

    // move para baixo
    if (i + 1 < M) {
        printPaths(mat, route, i + 1, j);
    }

    // move para a direita
    if (j + 1 < N) {
        printPaths(mat, route, i, j + 1);
    }

    // move na diagonal
    if (i + 1 < M && j + 1 < N) {
        printPaths(mat, route, i + 1, j + 1);
    }

    // retroceder
    route.pop_back();
}

// Imprime todas as rotas em uma grade retangular
void printPaths(vector<vector<int>> const& mat)
{
    // vetor para armazenar a rota atual
    vector<int> route;

    // inicia na primeira célula (0, 0)
    printPaths(mat, route, 0, 0);
}

int main()
{
    vector<vector<int>> mat =
    {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };

    printPaths(mat);

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
