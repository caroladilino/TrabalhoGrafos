#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <tuple>
#include <map>
#include "Grafo.h"

// 1. Declaração de todas as funções
template<typename T>
void buscaLargura(const structures::Grafo<T>& G, const T& s);

template<typename T>
void cicloEuleriano(const structures::Grafo<T>& G);

//ou djiskra, pode escolher
template<typename T>
void bellmanFord(const structures::Grafo<T>& G, const T& s);

template<typename T>
void floydWarshall(const structures::Grafo<T>& G);



// 2. Implementação de todas as funções
template<typename T>
void buscaLargura(const structures::Grafo<T>& G, const T& s){

    std::map<T, bool> map_conhecido;
    std::map<T, T> map_ancestral;
    std::map<T, int> map_distancia;
    
    //configurando todos os vertices
    for (auto const& par : G.vertices){
        T v = par.first;
        map_conhecido[v] = false;
        map_ancestral[v];
        map_distancia[v] = 10000;
    }
    //configurando o vértice de origem
    map_conhecido.at(s) = true;
    map_distancia.at(s) = 0;
    //preparando a fila de visitas
    std::queue<T> Q;
    Q.push(s);
    //Propagação das visitas
    while (!Q.empty()){
        T u = Q.front();
        Q.pop();
        for (const auto& v : G.vizinhos(u)){
            if (map_conhecido.at(v) == false){
                //conhecendo o vértice v
                map_conhecido.at(v) = true;
                map_distancia.at(v) = map_distancia.at(u) + 1;
                map_ancestral.at(v) = u;
                Q.push(v);
            }
        }
    }

    // Descobrindo a distância máxima (max_dist)
    int max_dist = 0;
    for (const auto& par : map_distancia) {
        if (par.second > max_dist && par.second != 10000) {
            max_dist = par.second;
        }
    }
    
    for (int i = 0; i <= max_dist; i++) {
        std::vector<T> vertices_no_nivel;
        for (const auto& [key, value] : map_distancia) {
            if (value == i) {
                vertices_no_nivel.push_back(key);
            }
        }

        // --- NOVA PROTEÇÃO: SÓ IMPRIME SE O NÍVEL NÃO ESTIVER VAZIO ---
        if (!vertices_no_nivel.empty()) {
            std::cout << i << ": ";
            std::sort(vertices_no_nivel.begin(), vertices_no_nivel.end());
            
            for (size_t j = 0; j < vertices_no_nivel.size(); j++) {
                std::cout << vertices_no_nivel[j];
                if (j < vertices_no_nivel.size() - 1) {
                    std::cout << ",";
                }
            }
            std::cout << "\n";
        }
    }
}

template<typename T>
    void buscaSubCiclo(T v, const structures::Grafo<T>& G, std::map<std::pair<T, T>, int>& aresta_visitada, std::vector<T>& ciclo) {
        
        // 1. Percorremos todos os vizinhos do vértice atual 'v'
        for (const T& u : G.vizinhos(v)) {
            
            // 2. Verificamos se a aresta entre 'v' e 'u' ainda está disponível
            if (aresta_visitada[{v, u}] > 0) {
                
                // a) "Gasta" a aresta nos dois sentidos, diminuindo o contador
                aresta_visitada[{v, u}]--;
                aresta_visitada[{u, v}]--;
                
                // b) Chamada recursiva para continuar a exploração a partir de 'u'
                buscaSubCiclo(u, G, aresta_visitada, ciclo);
            }
        }
        
        // c) Vértice ficou sem opções de saída, adicionamos ao ciclo (caminho)
        ciclo.push_back(v);
    }



template<typename T>
void cicloEuleriano(const structures::Grafo<T>& G){

    std::map<std::pair<T, T>, int> aresta_visitada;

   // 1. Caso base
    if (G.qtdArestas() == 0) {
        std::cout << "0\n";
        return;
    }

    //2. Inicializando todos como não conhecidos
    for (const auto& par_u : G.vertices) {
        T u = par_u.first;
        for (const auto& vizinho : par_u.second.vizinhos) {
            T v = vizinho.first;
            aresta_visitada[{u, v}] = 0; 
        }
    }

    //3. Somando 1 a todos ( 1-> disponivel , 0-> indisponivel)
    for (const auto& par_u : G.vertices) {
        T u = par_u.first;
        for (const auto& vizinho : par_u.second.vizinhos) {
            T v = vizinho.first;
            aresta_visitada[{u, v}] = aresta_visitada[{u, v}] + 1 ; 
        }
    }

    for (const auto& par : G.vertices) {
        if (G.grau(par.first) % 2 != 0) {
            std::cout << "0\n"; // Imprime 0 indicando que o ciclo é impossível
            return; // Aborta a função imediatamente
        }
    }


    //pegando um vértice aleatório
    T inicio = G.vertices.begin()->first;
    std::vector<T> ciclo_final;

    buscaSubCiclo(inicio, G, aresta_visitada, ciclo_final);

    if (ciclo_final.size() != G.qtdArestas() + 1) {
        std::cout << "0\n"; 
        return; 
    }

    std::reverse(ciclo_final.begin(), ciclo_final.end());

    // 7. Imprimindo o resultado
        std::cout << "1\n"; // Opcional: flag indicando que achou o ciclo
        for (size_t i = 0; i < ciclo_final.size(); i++) {
            std::cout << ciclo_final[i];
            if (i < ciclo_final.size() - 1) {
                std::cout << ",";
            }
        }
        std::cout << "\n";
    }
    
template<typename T>
void bellmanFord(const structures::Grafo<T>& G, const T& s){
    // entrada: grafo ponderado orientado/dirigido ou não
    std::map<T, T> map_ancestral; // lista dos ancestrais
    std::map<T, int> map_distancia; // lista das distancias

    //configurando todos os vertices
    for (auto const& par : G.vertices){
        T v = par.first;
        map_ancestral[v]; //inicializado com null já
        map_distancia[v] = 100000; // valor "infinito"
    }
    //configurando o vértice de origem
    map_distancia.at(s) = 0;

    for (int i = 1; i < G.qtdVertices(); i++) {
        for (const auto& par_u : G.vertices) { // foreach (u,v) in arestas -> pega u
            T u = par_u.first;
            if (map_distancia.at(u) == 100000) continue; // só tenta relaxar se ja chegou em u

            for (const auto& vizinho : par_u.second.vizinhos) { // foreach (u,v) in arestas -> pega v nos vizinhos
                T v = vizinho.first;

                int peso_uv = vizinho.second; // peso de u para v (ja estava na estrutura)
                if (map_distancia.at(v) > (map_distancia.at(u) + peso_uv)) {
                    map_distancia.at(v) = (map_distancia.at(u) + peso_uv);
                    map_ancestral.at(v) = u;
                }
            }
        } 
    }
    // verificar ciclos negativos
    for (const auto& par_u : G.vertices) {
        T u = par_u.first;
        if (map_distancia.at(u) == 100000) continue;

        for (const auto& vizinho : par_u.second.vizinhos) {
            T v = vizinho.first;

            int peso_uv = vizinho.second;
            if (map_distancia.at(v) > (map_distancia.at(u) + peso_uv)) {
                std::cout << "Erro: ciclo de peso negativo encontrado :(";
                return;
            }
        }
        
    }
    // print dos resultados
    for (const auto& par : G.vertices) {
        T destino = par.first;

        std::cout << destino << ": ";
        
        // se o vertice for inacessível
        if (map_distancia.at(destino) == 100000) {
            std::cout << "inacessível; d = infinito\n";
            continue;
        }
        // reconstruir caminho de trás pra frente
        std::vector<T> caminho;
        T atual = destino;

        while (atual != s) {
            caminho.push_back(atual);
            atual = map_ancestral.at(atual);
        }
        caminho.push_back(s);

        // printa o caminho na ordem certa (de s -> destino)
        for (int i = caminho.size() - 1; i >= 0; i--) {
            std::cout << caminho[i];
            if (i > 0) { // não vai printar no último
                std::cout << ",";
            }
        }
        std::cout << "; d=" << map_distancia.at(destino) << "\n";
    }
}

template<typename T>
void floydWarshall(const structures::Grafo<T>& G){
    int V = G.qtdVertices();
        if (V == 0) return;

        // 1. Extrair e ordenar os vértices (exigência do enunciado: "ordem crescente")
        std::vector<T> vertices;
        for (const auto& par : G.vertices) {
            vertices.push_back(par.first);
        }
        std::sort(vertices.begin(), vertices.end());

        // 2. Criar um mapeamento de Vértice (T) para Índice da Matriz (0 a V-1)
        std::map<T, int> map_index;
        for (int i = 0; i < V; ++i) {
            map_index[vertices[i]] = i;
        }

        // 3. Inicializar a matriz de distâncias
        // Usamos um valor alto o suficiente para simular o infinito, 
        // mas que não cause overflow (estouro de limite do int) na hora de somar.
        const int INFINITO = 100000000; 
        std::vector<std::vector<int>> dist(V, std::vector<int>(V, INFINITO));

        // A distância de um vértice para ele mesmo é 0
        for (int i = 0; i < V; ++i) {
            dist[i][i] = 0;
        }

        // Preencher a matriz com os pesos reais das arestas
        for (const auto& par : G.vertices) {
            T u = par.first;
            int u_idx = map_index[u];
            for (const auto& vizinho : par.second.vizinhos) {
                T v = vizinho.first;
                int peso = vizinho.second;
                int v_idx = map_index[v];
                dist[u_idx][v_idx] = peso;
            }
        }

        // 4. O coração do Algoritmo de Floyd-Warshall (O triplo loop: k, i, j)
        for (int k = 0; k < V; ++k) {
            for (int i = 0; i < V; ++i) {
                for (int j = 0; j < V; ++j) {
                    // Só tenta somar se houver caminho válido (evita somar infinito com infinito)
                    if (dist[i][k] != INFINITO && dist[k][j] != INFINITO) {
                        if (dist[i][k] + dist[k][j] < dist[i][j]) {
                            dist[i][j] = dist[i][k] + dist[k][j];
                        }
                    }
                }
            }
        }

        // 5. Impressão no formato estrito do corretor (ex: 1:0,10,3,5)
        for (int i = 0; i < V; ++i) {
            std::cout << vertices[i] << ":"; // Imprime o ID do vértice e os dois-pontos
            
            for (int j = 0; j < V; ++j) {
                std::cout << dist[i][j];
                
                // Imprime a vírgula apenas se NÃO for o último elemento da linha
                if (j < V - 1) {
                    std::cout << ",";
                }
            }
            std::cout << "\n"; // Quebra a linha para o próximo vértice
        }
    }


#endif