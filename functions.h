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
    for (int i=0; i < (map_distancia.size() - 1); i++){
        std::cout << i << ": ";
        for (const auto& [key, value] : map_distancia) {
            if (value == i){
                std::cout << key << ",";
            }
        }
        std::cout << "\n";
    }
    std::cout << "buscaLargura terminou de rodar" << "\n";
}


template<typename T>
void cicloEuleriano(const structures::Grafo<T>& G){
   //BOTAR CÓDIGO AQUI
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
            std::cout << "inacessível; d = infinito\n"
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
                std::cout << ","
            }
        }
        std::cout << "; d=" << map_distancia.at(destino) << "\n";
    }
}

template<typename T>
void floydWarshall(const structures::Grafo<T>& G){
    //BOTAR CÓDIGO AQUI
}

#endif