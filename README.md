# Backtracking
Exercicios de Backtracking
acktracking é um método para iterar (percorrer) todas as possíveis configurações em um espaço qualquer. É um algoritmo geral que poderá ser personalizado para cada tipo de aplicação. De modo geral, a solução será um vetor a = (a1, a2, …, a-n), sendo cada elemento a-i selecionado de um conjunto Si. Os exemplos mais comuns, os quais serão mostrados posteriormente, são a criação de permutações e de subconjuntos.

A cada passo do algoritmo, começa-se com uma solução parcial, diga-se a = (a1, a2, …, a-k), e tenta-se aumentá-la, adicionando outro elemento ao seu fim. Após adicioná-lo, é preciso testar se há uma solução completa – se sim, deve-se imprimí-la, contá-la ou qualquer ação necessária. Se não é necessário checar se essa solução parcial é ainda expansível para alguma completa. Se for, continue testando, se não, então apague o último elemento de a e teste outra possibilidade para aquela posição.


Características do Backtracking

-Algoritmos tentativa e erro não seguem regra fixa de computação:

-Passos em direção à solução final são tentados e registrados;
-Caso esses passos tomados não levem à solução final, eles podem ser retirados e apagados do registro.
-Quando a pesquisa na árvore de soluções cresce rapidamente é necessário usar algoritmos aproximados ou heurísticas que não garantem a solução ótima mas são rápidas.
-O número de escolhas cresce pelo menos exponencialmente com o tamanho da instância.
-Constrói a solução, um componente por vez, tentando terminar o processo tão logo quanto for possível identificar que uma solução não poderá ser feita obtida em razão das escolhas feitas.
-Esta técnica torna possível a resolução de muitos problemas NP-difícil com instâncias grandes em um tempo aceitável.
-Elimina um nó se for garantido que ele não levará a obtenção de uma solução para o problema.
-Faz busca em profundidade.
Backtracking assegura o acerto por enumerar todas as possilidades sem visitar nunca o mesmo estado, sendo também eficiente. A recursividade promove a elegância e a fácil implementação desse algoritmo, porque o vetor de novos candidatos, c, é alocado com um procedimento recursivo.

As principais aplicações do backtracking são da criação de todos os subconjuntos de um conjunto S e na criação de todas as suas permutações.


Branch and bound é um paradigma de projeto de algoritmo que geralmente é usado para resolver problemas de otimização combinatória. Esses problemas são tipicamente exponenciais em termos de complexidade de tempo e podem exigir a exploração de todas as permutações possíveis no pior caso. A técnica do algoritmo Branch and Bound resolve esses problemas de forma relativamente rápida.


