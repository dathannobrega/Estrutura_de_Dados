#ifndef GRAFO_H_
#define GRAFO_H_

typedef struct grafo{
    int NumVert;
    int NumArco;
    struct noVert *vertices;
}Grafo;

typedef struct  noVert
{
    int vert;
    struct  noVert *prox;
    struct noAdj *ladj;
}NoVert;

typedef struct noAdj
{
    int vert;
    struct noAdj *prox;
}NoAdj;


Grafo* criarGrafo(int nVert);
void inserirArco(Grafo *G, int v1, int v2);
void inserirNovoVertice(Grafo *G, int nv);
void imprimirListaAdj(Grafo *G);
NoVert* inserirVertice(NoVert *ini, int num);
NoAdj* inserirAdjacencia(int v2,NoAdj *Adj);

int RemoveArco(Grafo *G,int v1,int v2);
int RemoveVertice(Grafo *G,int v1);
int procuraArco();
int CalculaGrau();
void DestruirGrafo();


#endif // GRAFO_H_