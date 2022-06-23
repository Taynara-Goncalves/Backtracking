// ciclohamiltoniano.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

//Dado um grafo não direcionado, imprima todos os caminhos hamiltonianos presentes nele.
//O caminho hamiltoniano em um grafo direcionado ou não direcionado é um caminho que visita 
//cada vértice exatamente uma vez.

#include <iostream>
#include <vector>
using namespace std;

// Estrutura de dados para armazenar uma aresta do gráfico
struct Edge {
    int src, dest;
};

// Uma classe para representar um objeto gráfico
class Graph
{
public:
    // um vetor de vetores para representar uma lista de adjacências
    vector<vector<int>> adjList;

    // Construtor
    Graph(vector<Edge> const& edges, int n)
    {
        // redimensiona o vetor para conter `n` elementos do tipo `vector<int>`
        adjList.resize(n);

        // adiciona arestas ao grafo não direcionado
        for (Edge edge : edges)
        {
            int src = edge.src;
            int dest = edge.dest;

            adjList[src].push_back(dest);
            adjList[dest].push_back(src);
        }
    }
};

// Função utilitária para imprimir um caminho
void printPath(vector<int> const& path)
{
    for (int i : path) {
        cout << i << ' ';
    }
    cout << endl;
}

void hamiltonianPaths(Graph const& graph, int v, vector<bool>& visited,
    vector<int>& path, int n)
{
    // se todos os vértices forem visitados, então o caminho hamiltoniano existe
    if (path.size() == n)
    {
        // imprime o caminho hamiltoniano
        printPath(path);
        return;
    }

    // Verifica se toda aresta começando no vértice `v` leva a uma solução ou não
    for (int w : graph.adjList[v])
    {
        // processa apenas vértices não visitados como o Hamiltoniano
        // caminho visita cada vértice exatamente uma vez
        if (!visited[w])
        {
            visited[w] = true;
            path.push_back(w);

            // verifica se adicionar o vértice `w` ao caminho leva à solução ou não
            hamiltonianPaths(graph, w, visited, path, n);

            // retroceder
            visited[w] = false;
            path.pop_back();
        }
    }
}

void findHamiltonianPaths(Graph const& graph, int n)
{
    //começa com cada nó
    for (int start = 0; start < n; start++)
    {
        // adiciona o nó inicial ao caminho
        vector<int> path;
        path.push_back(start);

        // marca o nó inicial como visitado
        vector<bool> visited(n);
        visited[start] = true;

        hamiltonianPaths(graph, start, visited, path, n);
    }
}

int main()
{
    // considera um grafo completo com 4 vértices
    vector<Edge> edges = {
        {0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 3}
    };

    // número total de nós no gráfico (rotulado de 0 a 3)
    int n = 4;

    // constrói um gráfico a partir das arestas fornecidas
    Graph graph(edges, n);

    findHamiltonianPaths(graph, n);

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
