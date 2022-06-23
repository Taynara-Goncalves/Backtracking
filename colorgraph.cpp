// colorgraph.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

//Dado um grafo não direcionado, verifique se ele é k - colorível ou não
//e imprima todas as configurações possíveis de atribuição de cores aos seus vértices.


#include <iostream>
#include <vector>
#include <iomanip>
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
    vector<vector<int>> adj;

    // Construtor
    Graph(vector<Edge> const& edges, int n)
    {
        // redimensiona o vetor para conter `n` elementos do tipo `vector<int>`
        adj.resize(n);

        // adiciona arestas ao grafo não direcionado
        for (Edge edge : edges)
        {
            int src = edge.src;
            int dest = edge.dest;

            adj[src].push_back(dest);
            adj[dest].push_back(src);
        }
    }
};

// Um array de strings para armazenar cores (pode lidar com gráficos de 10 cores)
string COLORS[] = { "", "BLUE", "GREEN", "RED", "YELLOW", "ORANGE",
                "PINK", "BLACK", "BROWN", "WHITE", "PURPLE" };

// Função para verificar se é seguro atribuir a cor `c` ao vértice `v`
bool isSafe(Graph const& graph, vector<int> color, int v, int c)
{
    // verifica a cor de cada vértice adjacente de `v`
    for (int u : graph.adj[v])
    {
        if (color[u] == c) {
            return false;
        }
    }

    return true;
}

void kColorable(Graph const& graph, vector<int>& color, int k, int v, int n)
{
    // se todas as cores forem atribuídas, imprime a solução
    if (v == n)
    {
        for (int v = 0; v < n; v++) {
            cout << setw(8) << left << COLORS[color[v]];
        }
        cout << endl;

        return;
    }

    // tenta todas as combinações possíveis de cores disponíveis
    for (int c = 1; c <= k; c++)
    {
        // se é seguro atribuir a cor `c` ao vértice `v`
        if (isSafe(graph, color, v, c))
        {
            // atribui a cor `c` ao vértice `v`
            color[v] = c;

            //recorre para o próximo vértice
            kColorable(graph, color, k, v + 1, n);

            // retroceder
            color[v] = 0;
        }
    }
}

int main()
{
    // vetor de arestas do gráfico conforme o diagrama acima
    vector<Edge> edges = {
        {0, 1}, {0, 4}, {0, 5}, {4, 5}, {1, 4}, {1, 3}, {2, 3}, {2, 4}
    };

    // número total de nós no gráfico
    int n = 6;

    // constrói um gráfico a partir das arestas fornecidas
    Graph g(edges, n);

    int k = 3;

    vector<int> color(n, 0);

    // imprime todas as k-configurações coloridas do gráfico
    kColorable(g, color, k, 0, n);

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
