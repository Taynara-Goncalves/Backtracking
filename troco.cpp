// troco.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

/*
	Problema do número mínimo de moedas
	Resolução através de backtracking
*/

#include <iostream>
#define INFINITO 10000000

using namespace std;

int obter_min_moedas(int moedas[], int troco, int tam_moedas)
{
	int min_moedas = INFINITO;

	if (troco == 0)
		return 0;

	for (int i = 0; i < tam_moedas; i++)
	{
		if (troco >= moedas[i])
		{
			int cont = 1 + obter_min_moedas(moedas, troco - moedas[i], tam_moedas);

			if (min_moedas > cont)
				min_moedas = cont;
		}
	}

	return min_moedas;
}

int main(int argc, char* argv[])
{
	int moedas[] = { 1, 2, 3, 4 };
	int troco = 3;
	int tam_moedas = sizeof(moedas) / sizeof(int);

	cout << obter_min_moedas(moedas, troco, tam_moedas);

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
