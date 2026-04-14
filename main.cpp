// Copyright [2026] Carolina Adilino
#include <list>
#include <algorithm>


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
            //ler(arquivo)2
        
        private:
            std::list<T> vertices;
            std::list<T> arestas; //decidir como armazenar arestas 
            int funcao(std::list<T> arestas)

    };

    //botar construtores e destrutores?

    //Função retorna quantidade de vértices 
    template<typename T>
    int structures::Grafo<T>::qtdVertices(){
        return vertices.size();
    }

    template<typename T>
    int structures::Grafo<T>::qtdArestas(){
        return arestas.size();
    }

    template<typename T>
    int structures::Grafo<T>::grau(const T& vertice){
        //botar codigo aqui
    }

    template<typename T>
    int structures::Grafo<T>::rotulo(const T& vertice){
        //botar codigo aqui
    }

    template<typename T>
    std::list<T> structures::Grafo<T>::vizinhos(const T& vertice){
        //botar codigo aqui
    }

    template<typename T>
    bool structures::Grafo<T>::haAresta(const T& vertice1, const T& vertice2){
        //botar codigo aqui
    }

    template<typename T>
    int structures::Grafo<T>::peso(const T& vertice1, const T& vertice2){
        //botar codigo aqui
    }
}


