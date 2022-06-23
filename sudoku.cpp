// sudoku.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>

using namespace std;

// N é o tamanho da matriz 2D N*N
#define N 9

/* Uma função utilitária para imprimir a grade */
void print(int arr[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

// Verifica se será
// legal para atribuir num ao
// linha dada, col
bool isSafe(int grid[N][N], int row,
    int col, int num)
{

    // Verifique se encontramos o mesmo número
    // na linha semelhante, 
    // retornamos false
    for (int x = 0; x <= 8; x++)
        if (grid[row][x] == num)
            return false;

    // Verifique se encontramos o mesmo número // na coluna semelhante, // retornamos false
    for (int x = 0; x <= 8; x++)
        if (grid[x][col] == num)
            return false;

    // Verifica se encontramos o mesmo número // na matriz 3*3 específica, // retornamos false
    int startRow = row - row % 3,
        startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j +
                startCol] == num)
                return false;

    return true;
}

/* Pega uma grade parcialmente preenchida e tenta
para atribuir valores a todos os locais não atribuídos em
de forma a cumprir os requisitos
Solução Sudoku (não duplicação entre linhas,
colunas e caixas) */
bool solveSudoku(int grid[N][N], int row, int col)
{
    // Verifica se chegamos ao 8º
      // linha e 9ª coluna (0
      // matriz indexada), estamos
      // retornando true para evitar
      // mais retrocesso
    if (row == N - 1 && col == N)
        return true;

    // Verifica se o valor da coluna se torna 9 ,
      // passamos para a próxima linha e
      // coluna começa em 0
    if (col == N) {
        row++;
        col = 0;
    }

    // Verifica se a posição atual de
     // a grade já contém
     // valor >0, iteramos para a próxima coluna
    if (grid[row][col] > 0)
        return solveSudoku(grid, row, col + 1);

    for (int num = 1; num <= N; num++)
    {

        //Verifica se é seguro colocar
         // o número (1-9) no
         // dado linha ,col ->we
         // move para a próxima coluna
        if (isSafe(grid, row, col, num))
        {

            /* Atribuindo o número em
                a corrente (linha, coluna)
                posição da grade
                e assumindo nossa atribuição
                num na posição
                está correto     */
            grid[row][col] = num;

            // Verificando a próxima possibilidade com next
             // coluna
            if (solveSudoku(grid, row, col + 1))
                return true;
        }

        // Removendo o num atribuído,
         // desde nossa suposição
         // estava errado, e vamos para
         // próxima suposição com
         // valor do diff
        grid[row][col] = 0;
    }
    return false;
}

// Driver Code
int main()
{
    // 0 means unassigned cells
    int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };

    if (solveSudoku(grid, 0, 0))
        print(grid);
    else
        cout << "no solution  exists " << endl;

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
