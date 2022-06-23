// imã.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

//Recebemos um conjunto de ímãs bipolares, cada um em forma de dominó. O objetivo é colocar 
//ímãs em um M × N placa, que satisfaça um conjunto de condições em que ambos M e N não são ímpares.

#include <iostream>
using namespace std;

// matriz `M × N`
#define M 5
#define N 6

// Função utilitária para imprimir a solução
void printSolution(char board[M][N])
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Função utilitária para contar o número total de caracteres `ch` na coluna atual `j`
int countInColumns(char board[N][N], char ch, int j)
{
    int count = 0;
    for (int i = 0; i < M; i++)
    {
        if (board[i][j] == ch) {
            count++;
        }
    }

    return count;
}

// Função utilitária para contar o número total de caracteres `ch` na linha atual `i`
int countInRow(char board[N][N], char ch, int i)
{
    int count = 0;
    for (int j = 0; j < N; j++)
    {
        if (board[i][j] == ch) {
            count++;
        }
    }

    return count;
}

// Função para verificar se é seguro colocar `ch` em `board[row][col]`
bool isSafe(char board[N][N], int row, int col, char ch, int top[],
    int left[], int bottom[], int right[])
{
    // verifica as células adjacentes
    if ((row - 1 >= 0 && board[row - 1][col] == ch) ||
        (col + 1 < N && board[row][col + 1] == ch) ||
        (row + 1 < M && board[row + 1][col] == ch) ||
        (col - 1 >= 0 && board[row][col - 1] == ch)) {
        return false;
    }

    // conta o caractere `ch` na linha atual
    int rowCount = countInRow(board, ch, row);

    // conta o caractere `ch` na coluna atual
    int colCount = countInColumns(board, ch, col);

    // se o caractere fornecido for `+`, verifique `top[]` e `left[]`
    if (ch == '+')
    {
        // verifica o topo
        if (top[col] != -1 && colCount >= top[col]) {
            return false;
        }

        // verifica a esquerda
        if (left[row] != -1 && rowCount >= left[row]) {
            return false;
        }
    }

    // se o caractere fornecido for `-`, verifique `bottom[]` e `right[]`
    if (ch == '-')
    {
        // verifica o fundo
        if (bottom[col] != -1 && colCount >= bottom[col]) {
            return false;
        }

        // verifica a esquerda
        if (right[row] != -1 && rowCount >= right[row]) {
            return false;
        }
    }

    return true;
}

// Função para validar a configuração de uma placa de saída
bool validateConfiguration(char board[N][N], int top[], int left[],
    int bottom[], int right[])
{
    // verifica o topo
    for (int i = 0; i < N; i++)
    {
        if (top[i] != -1 && countInColumns(board, '+', i) != top[i]) {
            return false;
        }
    }

    // verifica a esquerda
    for (int j = 0; j < M; j++)
    {
        if (left[j] != -1 && countInRow(board, '+', j) != left[j]) {
            return false;
        }
    }

    // verifica o fundo
    for (int i = 0; i < N; i++)
    {
        if (bottom[i] != -1 && countInColumns(board, '-', i) != bottom[i]) {
            return false;
        }
    }

    //verifica certo
    for (int j = 0; j < M; j++)
    {
        if (right[j] != -1 && countInRow(board, '-', j) != right[j]) {
            return false;
        }
    }

    return true;
}

// A principal função para resolver o quebra-cabeça dos Ímãs Bipolares
bool solveMagnetPuzzle(char board[N][N], int row, int col, int top[],
    int left[], int bottom[], int right[], char rules[M][N])
{
    // se a última célula for alcançada
    if (row >= M - 1 && col >= N - 1)
    {
        if (validateConfiguration(board, top, left, bottom, right)) {
            return true;
        }

        return false;
    }

    // se a última coluna da linha atual já estiver processada,
    // vai para a próxima linha, a primeira coluna
    if (col >= N)
    {
        col = 0;
        row = row + 1;
    }

    // se a célula atual contiver `R` ou `B` (fim da horizontal
    // ou slot vertical), recorrente para a próxima célula
    if (rules[row][col] == 'R' || rules[row][col] == 'B')
    {
        if (solveMagnetPuzzle(board, row, col + 1, top,
            left, bottom, right, rules)) {
            return true;
        }
    }

    // se o slot horizontal contém `L` e `R`
    if (rules[row][col] == 'L' && rules[row][col + 1] == 'R')
    {
        // coloca (`+`, `-`) par e retorna
        if (isSafe(board, row, col, '+', top, left, bottom, right) &&
            isSafe(board, row, col + 1, '-', top, left, bottom, right))
        {
            board[row][col] = '+';
            board[row][col + 1] = '-';

            if (solveMagnetPuzzle(board, row, col + 2,
                top, left, bottom, right, rules)) {
                return true;
            }

            // se não levar a uma solução, retrocede
            board[row][col] = 'X';
            board[row][col + 1] = 'X';
        }

        // coloca (`-`, `+`) par e retorna
        if (isSafe(board, row, col, '-', top, left, bottom, right) &&
            isSafe(board, row, col + 1, '+', top, left, bottom, right))
        {
            board[row][col] = '-';
            board[row][col + 1] = '+';

            if (solveMagnetPuzzle(board, row, col + 2,
                top, left, bottom, right, rules)) {
                return true;
            }

            // se não levar a uma solução, retrocede
            board[row][col] = 'X';
            board[row][col + 1] = 'X';
        }
    }

    // se o slot vertical contiver `T` e `B`
    if (rules[row][col] == 'T' && rules[row + 1][col] == 'B')
    {
        // coloca (`+`, `-`) par e retorna
        if (isSafe(board, row, col, '+', top, left, bottom, right) &&
            isSafe(board, row + 1, col, '-', top, left, bottom, right))
        {
            board[row][col] = '+';
            board[row + 1][col] = '-';

            if (solveMagnetPuzzle(board, row, col + 1,
                top, left, bottom, right, rules)) {
                return true;
            }

            // se não levar a uma solução, retrocede
            board[row][col] = 'X';
            board[row + 1][col] = 'X';
        }

        // coloca (`-`, `+`) par e retorna
        if (isSafe(board, row, col, '-', top, left, bottom, right) &&
            isSafe(board, row + 1, col, '+', top, left, bottom, right))
        {
            board[row][col] = '-';
            board[row + 1][col] = '+';

            if (solveMagnetPuzzle(board, row, col + 1,
                top, left, bottom, right, rules)) {
                return true;
            }

            // se não levar a uma solução, retrocede
            board[row][col] = 'X';
            board[row + 1][col] = 'X';
        }
    }

    // ignora a célula atual e retorna
    if (solveMagnetPuzzle(board, row, col + 1,
        top, left, bottom, right, rules)) {
        return true;
    }

    // se nenhuma solução for possível, retorna false
    return false;
}

void solveMagnetPuzzle(int top[], int left[], int bottom[],
    int right[], char rules[M][N])
{
    // para armazenar o resultado
    char board[M][N];

    // inicializa todas as células por `X`
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++) {
            board[i][j] = 'X';
        }
    }

    // inicia da célula `(0, 0)`
    if (!solveMagnetPuzzle(board, 0, 0, top, left, bottom, right, rules))
    {
        cout << "Solution does not exist";
        return;
    }

    // imprime o resultado se a configuração dada for solucionável
    printSolution(board);
}

int main()
{
    // indica a contagem de `+` ou `-` na parte superior (+), inferior (-),
    // bordas esquerda (+) e direita (-), respectivamente.
    // Valor de -1 indica qualquer número de sinais `+` ou `-`
    int top[N] = { 1, -1, -1, 2, 1, -1 };
    int bottom[N] = { 2, -1, -1, 2, -1, 3 };
    int left[M] = { 2, 3, -1, -1, -1 };
    int right[M] = { -1, -1, -1, 1, -1 };

    // matriz de regras
    char rules[M][N] =
    {
        { 'L', 'R', 'L', 'R', 'T', 'T' },
        { 'L', 'R', 'L', 'R', 'B', 'B' },
        { 'T', 'T', 'T', 'T', 'L', 'R' },
        { 'B', 'B', 'B', 'B', 'T', 'T' },
        { 'L', 'R', 'L', 'R', 'B', 'B' }
    };

    solveMagnetPuzzle(top, left, bottom, right, rules);

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
