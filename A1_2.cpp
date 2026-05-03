#include "functions.h"
#include <iostream>
#include <fstream>
#include <string> // Essencial para a conversão de texto para número

int main(int argc, char* argv[]) {
    
    // 1. Verificação de Segurança
    // argc deve ser 3: [0] = ./programa, [1] = arquivo.net, [2] = vertice_origem
    if (argc != 3) {
        std::cerr << "Erro: O programa espera exatamente 2 parametros.\n";
        std::cerr << "Uso correto: " << argv[0] << " <arquivo_do_grafo> <vertice_origem>\n";
        return 1; // Encerra com erro
    }

    // 2. Coletando os parâmetros do terminal
    std::string nomeArquivo = argv[1];
    
    // Converte o texto (ex: "1") do terminal para um número inteiro
    int verticeOrigem = std::stoi(argv[2]); 

    // 3. Abrindo o arquivo
    std::ifstream arquivoEntrada(nomeArquivo);

    if (!arquivoEntrada.is_open()) {
        std::cerr << "Erro: Nao foi possivel abrir o arquivo " << nomeArquivo << "\n";
        return 1;
    }

    // 4. Carregando o grafo
    structures::Grafo<int> meuGrafo1;
    meuGrafo1.ler(arquivoEntrada);
    arquivoEntrada.close(); 
    
    // 5. Executando a Busca em Largura com o vértice capturado
    buscaLargura(meuGrafo1, verticeOrigem);
    
    return 0; // Encerra com sucesso (sistemas automáticos exigem esse return 0)
}