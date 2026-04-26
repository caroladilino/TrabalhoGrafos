#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "Grafo.h"

// 1. Declaração (Protótipo)
template<typename T>
void buscaLargura(const structures::Grafo<T>& G, const T& s);

// 2. Implementação (O compilador precisa dela AQUI)
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

#endif