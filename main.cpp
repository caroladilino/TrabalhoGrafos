#include "functions.h"


int main(int argc, char* argv[]){
    //todo: alterar pra receceber o nome do arquivo pelo terminal
    
    structures::Grafo<int> meuGrafo1;
    std::ifstream arquivoEntrada("grafo.txt");
    meuGrafo1.ler(arquivoEntrada);
    //printando o grafo só pra degubar
    //for (auto const& v : meuGrafo1.vertices) {  // v = <T, Vertice>
    //    std::cout << v.first << ": ";
    //    for (auto const& u : v.second.vizinhos) { //u = pair<int, int>
    //        std::cout << "{" << u.first << "," << u.second << "} ";}
    //    std::cout << std::endl;}
    
    buscaLargura(meuGrafo1, 1);
    std::cout << "main rodou ctinho" << "\n";
    return 0;
}
