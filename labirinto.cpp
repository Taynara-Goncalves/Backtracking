// labirinto.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

//Encontre o caminho mais curto em um labirinto
//Dado um Labirinto na forma de uma matriz retangular binária, encontre o comprimento do 
//caminho mais curto no labirinto de uma determinada fonte a um determinado destino.
//O caminho só pode ser construído a partir de células com valor 1 e, a qualquer momento 
//só podemos mover um passo em uma das quatro direções.

#include <iostream>
#include <vector>
#include <climits>
#include <cstring>

using namespace std;

// Verifica se é possível ir para (x, y) da posição atual. o
// função retorna false se a célula tiver valor 0 ou já visitada
bool isSafe(vector<vector<int>>& mat, vector<vector<bool>>& visited, int x, int y)
{
    return (x >= 0 && x < mat.size() && y >= 0 && y < mat[0].size()) &&
        mat[x][y] == 1 && !visited[x][y];
}

// Encontra a rota mais curta possível em uma matriz `mat` da célula de origem (i, j)
// para a célula de destino (x, y).

// `min_dist` é passado por referência e armazena o comprimento do caminho mais longo
// da origem para um destino encontrado até agora, e `dist` mantém o comprimento
// do caminho de uma célula de origem para uma célula atual (i, j).

void findShortestPath(vector<vector<int>>& mat, vector<vector<bool>>& visited,
    int i, int j, int x, int y, int& min_dist, int dist)
{
    // se o destino for encontrado, atualize `min_dist`
    if (i == x && j == y)
    {
        min_dist = min(dist, min_dist);
        return;
    }

    // define (i, j) célula como visitada
    visited[i][j] = true;

    // vai para a célula inferior
    if (isSafe(mat, visited, i + 1, j)) {
        findShortestPath(mat, visited, i + 1, j, x, y, min_dist, dist + 1);
    }

    //vai para a célula certa
    if (isSafe(mat, visited, i, j + 1)) {
        findShortestPath(mat, visited, i, j + 1, x, y, min_dist, dist + 1);
    }

    // vai para a célula superior
    if (isSafe(mat, visited, i - 1, j)) {
        findShortestPath(mat, visited, i - 1, j, x, y, min_dist, dist + 1);
    }

    // vai para a célula esquerda
    if (isSafe(mat, visited, i, j - 1)) {
        findShortestPath(mat, visited, i, j - 1, x, y, min_dist, dist + 1);
    }

    // backtrack: remove (i, j) da matriz visitada
    visited[i][j] = false;
}

// Wrapper sobre a função findShortestPath()
int findShortestPathLength(vector<vector<int>>& mat, pair<int, int>& src,
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

    int min_dist = INT_MAX;
    findShortestPath(mat, visited, src.first, src.second, dest.first, dest.second,
        min_dist, 0);

    if (min_dist != INT_MAX) {
        return min_dist;
    }

    return -1;
}

int main()
{
    vector<vector<int>> mat =
    {
        { 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
        { 0, 1, 1, 1, 1, 1, 0, 1, 0, 1 },
        { 0, 0, 1, 0, 1, 1, 1, 0, 0, 1 },
        { 1, 0, 1, 1, 1, 0, 1, 1, 0, 1 },
        { 0, 0, 0, 1, 0, 0, 0, 1, 0, 1 },
        { 1, 0, 1, 1, 1, 0, 0, 1, 1, 0 },
        { 0, 0, 0, 0, 1, 0, 0, 1, 0, 1 },
        { 0, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
        { 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
        { 0, 0, 1, 0, 0, 1, 1, 0, 0, 1 },
    };

    pair<int, int> src = make_pair(0, 0);
    pair<int, int> dest = make_pair(7, 5);

    int min_dist = findShortestPathLength(mat, src, dest);
    if (min_dist != -1)
    {
        cout << "The shortest path from source to destination "
            "has length " << min_dist;
    }
    else {
        cout << "Destination cannot be reached from a given source";
    }

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
