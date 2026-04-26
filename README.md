<h3>TO-DO:</h3>

- ajeitar para funções usarem infinito (por enquanto usam 1000)
- fazer programa receber como argumento o nome do arquivo a ser lido e o vértice a ser usado
- programar os algoritmos
    - cicloEuleriano
    - bellmanFord ou djikstra
    - floydWarshall

<h3>organização dos arquivos:</h3>
- main.cpp
    Esse é o arquivo que você vai dar run. Chame a função de ler grafo aqui, e passe esse grafo como argumento para outras funções que quiser chamar. Também tem comentado algumas linhas de código que irão printar o grafo após a leitura, caso queiram checar se essa parte está funcionando. Segundo os requisitos do projeto, precisa receber o nome do arquivo com a info do grafo e o vertice desejado no terminal. Pra facilitar o desenvolvimento das funções, essa parte ainda não foi adicionada (é bem mais fácil usar o próprio run do vscode com um arquivo e vértices pré selecionados) podem deixar essa parte pra mim.

- Grafo.h
    É aqui que temos a estrutura do grafo. Ele recebe um tipo não definido T, e monta um map com uma chave T indicando para um Vértice. Esse "Vértice" é uma estrutura que apresenta um rótulo e uma lista de arestas com seus pesos. Essa implementação ficou um pouco confusa, mas foi a melhor solução que achei. Se quiserem mudar algo, façam em uma branch separada e avisem, pq a sintaxe de todas as funçõe svai ter que mudar. É nesse arquivo que as funções do grafo estão definidas, usem elas a vontade nos algoritmos.

- functions.h
    É aqui que as funções que vamos desenvolver estão, já está tudo preparado com a parte que precisa indicar em destaque. Só copiar os algoritmos da apostila. O de busca em largura já está pronto, usem de inspiração de como manipular o grafo :)

- grafo.txt
    Exemplo de arquivo de um grafo do jeito correto. usem para debugar e se quiserem alterar alterem.
