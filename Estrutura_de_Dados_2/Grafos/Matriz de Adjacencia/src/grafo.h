#ifndef GRAFO_H_
#define GRAFO_H_


    typedef struct tipografo{
        int numVerti;
        int numArest;
        int** Mat;
    }TipoGrafo;

    TipoGrafo* CriarGrafo(int numVerti);
    TipoGrafo* liberarGrafo(TipoGrafo* G);

    int inserirAresta(TipoGrafo *G, int v1, int v2);
    int retirarAresta(TipoGrafo *Grafo, int v1, int v2);
    void exibirGrafo(TipoGrafo *G);
    void exibirMatriz(TipoGrafo *G);

#endif //GRAFO_H_

