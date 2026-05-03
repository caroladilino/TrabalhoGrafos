#include "functions.h"
#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
    
    // 1. Verificando se o usuário passou o nome do arquivo no terminal
    if (argc < 2) {
        std::cerr << "Erro: Uso correto: " << argv[0] << " <nome_do_arquivo.txt>\n";
        return 1; // Retorna erro
    }

    structures::Grafo<int> meuGrafo1;
    
    // 2. Abrindo o arquivo passado pelo terminal (argv[1])
    std::ifstream arquivoEntrada(argv[1]);

    // 3. Verificando se o arquivo abriu corretamente
    if (!arquivoEntrada.is_open()) {
        std::cerr << "Erro: Nao foi possivel abrir o arquivo " << argv[1] << "\n";
        return 1; // Retorna erro
    }

    // Carregando o grafo
    meuGrafo1.ler(arquivoEntrada);
    arquivoEntrada.close(); // Boa prática: fechar o arquivo após o uso

    /* Printando o grafo só pra debugar
    for (auto const& v : meuGrafo1.vertices) {  
        std::cout << v.first << ": ";
        for (auto const& u : v.second.vizinhos) { 
            std::cout << "{" << u.first << "," << u.second << "} ";
        }
        std::cout << std::endl;
    }
    */
    
    // Testando a Busca em Largura
    buscaLargura(meuGrafo1, 1);
    
    // Testando o Ciclo Euleriano (Hierholzer) que fizemos anteriormente
    cicloEuleriano(meuGrafo1);

    std::cout << "main rodou certinho\n";
    return 0;
}