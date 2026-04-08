// Copyright [2026] Carolina Adilino

//namespace = uma região do código 
namespace structures {
    
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
            T vizinhos(const T& vertice);

            //se {u, v} ∈ E, retorna verdadeiro e se não existir, retorna falso
            bool haAresta(const T& vertice1, const T& vertice2);

            //se {u, v} ∈ E, retorna o peso da aresta {u, v} se não existir, retorna um valor infinito positivo
            int peso(const T& vertice1, const T& vertice2);

            // deve carregar um grafo a partir de um arquivo no formato especificado ao final deste documento.
            //ler(arquivo)2
        
        private:
            std::list<T> vertices;
            std::list<T> arestas;
            int funcao(std::list<T> arestas)

    };
}


