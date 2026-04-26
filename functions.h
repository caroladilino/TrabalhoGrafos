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

    std::map<T, bool> vetor_conhecido;
    std::map<T, T> vetor_ancestral;
    std::map<T, int> vetor_distancia;
    
    //configurando todos os vertices
    for (auto const& par : G.vertices){
        T v = par.first;
        vetor_conhecido[v] = false;
        vetor_ancestral[v];
        vetor_distancia[v] = 10000;
    }

    //configurando o vértice de origem
    vetor_conhecido.at(s) = true;
    vetor_distancia.at(s) = 0;

    //preparando a fila de visitas
    std::queue<T> Q;
    Q.push(s);

    std::cout << Q.front();
    std::cout << "buscaLargura rodou ctinho";


}

#endif