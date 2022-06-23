// cavaleiro.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

//Imprima todos os passeios possíveis do Cavaleiro em um tabuleiro de xadrez
//Dado um tabuleiro de xadrez, imprima todas as sequências de movimentos de um cavalo em um 
//tabuleiro de modo que o cavalo visite cada casa apenas uma vez.

#include <iostream>
#include <cstring>

using namespace std;

// tabuleiro de xadrez `N × N`
#define N 5

// Os arrays abaixo detalham todos os oito movimentos possíveis para um cavalo.
// É importante evitar alterar a sequência dos arrays abaixo
int row[] = { 2, 1, -1, -2, -2, -1, 1, 2, 2 };
int col[] = { 1, 2, 2, 1, -1, -2, -2, -1, 1 };

// Verifica se `(x, y)` são coordenadas válidas do tabuleiro de xadrez.
// Note que um cavalo não pode sair do tabuleiro
bool isValid(int x, int y)
{
    if (x < 0 || y < 0 || x >= N || y >= N) {
        return false;
    }

    return true;
}

// Função recursiva para realizar o passeio do cavaleiro usando backtracking
void knightTour(int visited[N][N], int x, int y, int pos)
{
    // marca o quadrado atual como visitado
    visited[x][y] = pos;

    // se todos os quadrados forem visitados, imprime a solução
    if (pos >= N * N)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++) {
                cout << visited[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;

        // volta antes de retornar
        visited[x][y] = 0;
        return;
    }

    // verifica todos os oito movimentos possíveis para um cavalo
    // e se repete para cada movimento válido
    for (int k = 0; k < 8; k++)
    {
        // pega a nova posição do cavalo da atual
        // posição no tabuleiro
        int newX = x + row[k];
        int newY = y + col[k];

        // se a nova posição é válida e ainda não foi visitada
        if (isValid(newX, newY) && !visited[newX][newY]) {
            knightTour(visited, newX, newY, pos + 1);
        }
    }

    // retrocede do quadrado atual e remove-o do caminho atual
    visited[x][y] = 0;
}

int main()
{
    // `visited[][]` serve para dois propósitos:
    // 1. Mantém o registro das casas envolvidas no passeio do cavalo.
    // 2. Armazena a ordem em que os quadrados são visitados.
    int visited[N][N];

    // inicializa `visited[][]` por 0 (não visitado)
    memset(visited, 0, sizeof visited);

    int pos = 1;

    // inicia o passeio do cavalo a partir do quadrado do canto `(0, 0)`
    knightTour(visited, 0, 0, pos);

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
