// rotamaislonga.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//


#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

// Verifica se é possível ir para a posição (x, y) de
// a posição atual. A função retorna false se a célula
// tem valor 0, ou já foi visitado.
bool isSafe(vector<vector<int>>& mat, vector<vector<bool>>& visited, int x, int y)
{
    return (x >= 0 && x < mat.size() && y >= 0 && y < mat[0].size()) &&
        mat[x][y] == 1 && !visited[x][y];
}

// Encontra a rota mais longa possível em uma matriz `mat` da célula de origem
// (i, j) para a célula de destino (x, y).
// `max_dist` —> acompanha o comprimento do caminho mais longo da fonte para
// destino. É passado por referência.
// `dist` —> comprimento do caminho da célula de origem para a célula atual (i, j).
void findLongestPath(vector<vector<int>>& mat, vector<vector<bool>>& visited,
    int i, int j, int x, int y, int& max_dist, int dist)
{
    // se o destino não for possível da célula atual
    if (mat[i][j] == 0) {
        return;
    }

    // se o destino for encontrado, atualize `max_dist`
    if (i == x && j == y)
    {
        max_dist = max(dist, max_dist);
        return;
    }

    // define (i, j) célula como visitada
    visited[i][j] = 1;

    // vai para a célula inferior
    if (isSafe(mat, visited, i + 1, j)) {
        findLongestPath(mat, visited, i + 1, j, x, y, max_dist, dist + 1);
    }

    //vai para a célula certa
    if (isSafe(mat, visited, i, j + 1)) {
        findLongestPath(mat, visited, i, j + 1, x, y, max_dist, dist + 1);
    }

    // vai para a célula superior
    if (isSafe(mat, visited, i - 1, j)) {
        findLongestPath(mat, visited, i - 1, j, x, y, max_dist, dist + 1);
    }

    // vai para a célula esquerda
    if (isSafe(mat, visited, i, j - 1)) {
        findLongestPath(mat, visited, i, j - 1, x, y, max_dist, dist + 1);
    }

    // backtrack: remove (i, j) da matriz visitada
    visited[i][j] = 0;
}

// Wrapper sobre a função findLongestPath()
int findLongestPathLength(vector<vector<int>>& mat, pair<int, int>& src,
    pair<int, int>& dest)
{
    // caso base: entrada inválida
    if (mat.size() == 0 || mat[src.first][src.second] == 0 ||
        mat[dest.first][dest.second] == 0) {
        return -1;
    }

    // matriz `M × N`
    int M = mat.size();
    int N = mat[0].size();

    // constrói uma matriz `M × N` para acompanhar as células visitadas
    vector<vector<bool>> visited;
    visited.resize(M, vector<bool>(N));

    int max_dist = 0;
    findLongestPath(mat, visited, src.first, src.second, dest.first, dest.second,
        max_dist, 0);

    return max_dist;
}

int main()
{
    //matriz de entrada
    vector<vector<int>> mat =
    {
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
        { 0, 0, 0, 0, 1, 0, 0, 1, 0, 0 },
        { 1, 0, 0, 0, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
        { 1, 0, 0, 0, 1, 0, 0, 1, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 0, 0, 1, 1 },
        { 1, 1, 0, 0, 1, 0, 0, 0, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 }
    };

    // (0, 0) são a célula de origem e (5, 7) são as coordenadas da célula de destino
    pair<int, int> src = make_pair(0, 0);
    pair<int, int> dest = make_pair(5, 7);

    cout << "The Maximum length path is " << findLongestPathLength(mat, src, dest);

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
