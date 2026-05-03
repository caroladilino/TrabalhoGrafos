#include "functions.h"
#include <fstream>
#include <string>

// MAIN EXCLUSIVA PARA A1_3 (Ciclo Euleriano)
int main(int argc, char* argv[]) {
    
    // Se não passar o arquivo, apenas encerra em silêncio. Sem prints de "Erro:"!
    if (argc < 2) { 
        return 1; 
    }

    std::string nomeArquivo = argv[1];
    std::ifstream arquivoEntrada(nomeArquivo);

    if (!arquivoEntrada.is_open()) {
        return 1; // Encerra em silêncio
    }

    structures::Grafo<int> meuGrafo1;
    meuGrafo1.ler(arquivoEntrada);
    arquivoEntrada.close(); 
    
    // Chama o algoritmo. A função cicloEuleriano já tem os couts corretos (0 ou 1 e o caminho).
    floydWarshall(meuGrafo1);
    
    return 0; // Fim silencioso
}