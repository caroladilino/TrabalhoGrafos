// Copyright [2026] Carolina Adilino
#include <list>
#include <algorithm>
#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

//namespace = uma região do código 
namespace structures {


    //Template = uma função sem tipo. imagina q qnd rodar o código "T" vira int ou float
    template<typename T>
    class Grafo{
        public:
            // Construtor padrão
            Grafo() = default;

            //método retorna quantidade de vértices
            int qtdVertices();

            //retorna a quantidade de arestas
            int qtdArestas();

            //retorna o grau do vértice v
            int grau(const T& v);

            //retorna o rótulo do vértice v
            int rotulo(const T& index);

            //retorna os vizinhos do vértice v
            std::list<T> vizinhos(const T& index);

            //se {u, v} ∈ E, retorna verdadeiro e se não existir, retorna falso
            bool haAresta(const T& index1, const T& index2);

            //se {u, v} ∈ E, retorna o peso da aresta {u, v} se não existir, retorna um valor infinito positivo
            int peso(const T& index1, const T& index2);

            // deve carregar um grafo a partir de um arquivo no formato especificado ao final deste documento.
            void ler(std::ifstream &arquivo);

            void buscaLargura(std::ifstream &arquivo, const T& vertice);
        
        public:
            struct Vertice {
                T rotulo; //rotulo do vertice
                std::list<std::pair<T, int>> vizinhos; // lista com pares <id do vizinho, peso da aresta>
            };
            
            //std::vector<Vertice> vetor_vertices;
            //se achar melhor usar o vetor, só mudar "vertices" para "vetor_vertices"
            std::map<T, Vertice> vertices;

    };


    //Função retorna quantidade de vértices 
    template<typename T>
    int structures::Grafo<T>::qtdVertices(){
        return vertices.size();
    }

    template<typename T>
    int structures::Grafo<T>::qtdArestas(){
        int contador = 0;
        for (const auto par : vertices){
            contador += par.second  .vizinhos.size();
        }
        return contador/2; //grafo não direcionado, vai contar tudo 2 vezes
    }
    
    template<typename T>
    int structures::Grafo<T>::grau(const T& index){
        return vertices.at(index).vizinhos.size();
    }

    template<typename T>
    int structures::Grafo<T>::rotulo(const T& index){
        return vertices.at(index).rotulo;
    }

    template<typename T>
    std::list<T> structures::Grafo<T>::vizinhos(const T& index){
        std::list<T> lista_vizinhos;
        for (auto par : vertices.at(index).vizinhos){
            lista_vizinhos.push_back(par.first);
        }
        return lista_vizinhos;
    }

    template<typename T>
    bool structures::Grafo<T>::haAresta(const T& index1, const T& index2){
        for (auto par : vertices.at(index1).vizinhos){
            if (par.first == index2){
                return true;
            }
        }
        return false;
    }

    template<typename T>
    int structures::Grafo<T>::peso(const T& index1, const T& index2){
        for (auto par : vertices.at(index1).vizinhos){
            if (par.first == index2){
                return par.second;
            }
        }
        return 100000; //MUDAR PARA INFINITO
    }
    template<typename T>
    void structures::Grafo<T>::ler(std::ifstream &arquivo) {
        std::string linha;
        std::string inicioVertices = "*vertices";

        if (std::getline(arquivo, linha)) {
            size_t pos = linha.find(inicioVertices);
            if (pos != std::string::npos) {
                std::string valor = linha.substr(pos + inicioVertices.length());
                int num = std::stoi(valor);
                for (int i = 1; i < num + 1; i++){
                    std::getline(arquivo, linha);
                    std::stringstream ss(linha);
                    T id;
                    ss >> id;
                    vertices[id] = {};
                }
                std::getline(arquivo, linha);
                while (std::getline(arquivo, linha)){
                    std::stringstream ss(linha);
                    T u, v;
                    int peso;

                    // This extracts the three values separated by spaces
                    if (ss >> u >> v >> peso) {
                        // Find the list associated with vertex 'u' and add the pair {v, peso}
                        vertices[u].vizinhos.emplace_back(v, peso);
                    }
                }
            }     
        } 
    }
    //pra debuggar: std::cout << linha << std::endl;


    //---BUSCA EM LARGURA---
    template<typename T>
    void structures::Grafo<T>::buscaLargura(std::ifstream &arquivo, const T& vertice){
        //ESCREVER O CÓDIGO AQUI
    }

}

int main(int argc, char* argv[]){
    //todo: alterar pra receceber o nome do arquivo pelo terminal
    structures::Grafo<std::string> meuGrafo1;
    std::ifstream arquivoEntrada("grafo.txt");

    meuGrafo1.ler(arquivoEntrada);

//            struct Vertice {
 //               T rotulo; //rotulo do vertice
//                std::list<std::pair<int, int>> vizinhos; // lista com pares <id do vizinho, peso da aresta>
//            };           
//            std::map<T, Vertice> vertices;


    //printando o grafo só pra degubar
    for (auto const& v : meuGrafo1.vertices) {  // v = <T, Vertice>
        std::cout << v.first << ": ";
        for (auto const& u : v.second.vizinhos) { //u = pair<int, int>

            std::cout << "{" << u.first << "," << u.second << "} ";

        }
        std::cout << std::endl;
    }
    
    return 0;
}

// TO-DO:
// - alterar estrutura de map para incluir o rótulo
// - fazer metodo retornar rotulo
// - ajeitar negocio lá infinito
// - fazer programa receber como argumento o nome do arquivo a ser lido
// - programar os algoritmos
// - separar em arquivos diferentes cada algoritmo