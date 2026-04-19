// Copyright [2026] Carolina Adilino
#include <list>
#include <algorithm>
#include <map>
#include <iostream>
#include <fstream>
#include <string>

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
            int grau(const T& vertice);

            //retorna o rótulo do vértice v
            int rotulo(const T& vertice);

            //retorna os vizinhos do vértice v
            std::list<T> vizinhos(const T& vertice);

            //se {u, v} ∈ E, retorna verdadeiro e se não existir, retorna falso
            bool haAresta(const T& vertice1, const T& vertice2);

            //se {u, v} ∈ E, retorna o peso da aresta {u, v} se não existir, retorna um valor infinito positivo
            int peso(const T& vertice1, const T& vertice2);

            // deve carregar um grafo a partir de um arquivo no formato especificado ao final deste documento.
            void ler(std::ifstream &arquivo);

            void buscaLargura(std::ifstream &arquivo, const T& vertice);
        
        private:
            // Mapa onde a chave é o vértice e o valor é uma lista de pares (vizinho, peso)
            std::map<T, std::list<std::pair<T, int> > > adjacencias;

    };


    //Função retorna quantidade de vértices 
    template<typename T>
    int structures::Grafo<T>::qtdVertices(){
        return adjacencias.size();
    }

    template<typename T>
    int structures::Grafo<T>::qtdArestas(){
        int contador = 0;
        for (auto [vertice,vizinhos] : adjacencias){
            contador += vizinhos.size();
        }
        return contador/2; //grafo não direcionado
    }
    
    template<typename T>
    int structures::Grafo<T>::grau(const T& vertice){
        //quantidade de vizinhos = tamanho da resposta de quando chamamos o hash para um vertice
        return adjacencias.at(vertice).size();
    }

    template<typename T>
    int structures::Grafo<T>::rotulo(const T& vertice){
        //BOTAR CÓDIGO AQUI
        return 0;
    }

    template<typename T>
    std::list<T> structures::Grafo<T>::vizinhos(const T& vertice){
        std::list<T> lista_vizinhos;
        for (auto par : adjacencias.at(vertice)){
            lista_vizinhos.push_back(par.first);
        }
        return lista_vizinhos;
    }

    template<typename T>
    bool structures::Grafo<T>::haAresta(const T& vertice1, const T& vertice2){
        for (auto par : adjacencias.at(vertice1)){
            if (par.first == vertice2){
                return true;
            }
        }
        return false;
    }

    template<typename T>
    int structures::Grafo<T>::peso(const T& vertice1, const T& vertice2){
        for (auto par : adjacencias.at(vertice1)){
            if (par.first == vertice2){
                return par.second;
            }
        }
        return 100000; //MUDAR PARA INFINITO
    }
    template<typename T>
    void structures::Grafo<T>::ler(std::ifstream &arquivo) {
        std::string linha;
        std::string inicioVertices = "*vertices";
        std::string inicioPesos = "*edges";

        if (std::getline(arquivo, linha)) {
            size_t pos = linha.find(inicioVertices);
            if (pos != std::string::npos) {
                std::string valor = linha.substr(pos + inicioVertices.length());
                int num = std::stoi(valor);
                for (int i = 0; i < num; i++){
                    std::getline(arquivo, linha);
                    //CRIAR UM ITEM NO MAP PARA CADA VERTICE
                    //pra debuggar: std::cout << linha << std::endl;
                }
                std::getline(arquivo, linha);
                while (std::getline(arquivo, linha)){
                    //pra debuggar: std::cout << linha << std::endl;
                    //MAPEAR CADA ARESTA
                }
            }     
        } 
    }

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

    return 0;
}