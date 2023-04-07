//1152 - Estradas escuras
//Problema de árvore geradora mínima: será utilizado o algoritmo de Kruskal
#include <stdio.h>
#include <stdlib.h>
#include<search.h>

#define N 3 //largura da matriz
#define M 200001 //comprimento máximo da matriz

int grafo[M][N], somaAGM; //definindo uma matriz que receberá o grafo

typedef struct no{ //nó para a lista encadeada das subárvores formadas durante o algoritmo de kruskal
    int n;
    struct no *prox;
}No;

int OrdenaArestas(const void *a, const void *b){ //ordenando as arestas pelo peso em ordem crescente
    const int *x = a, *y = b;

    if (grafo[*x][2] < grafo[*y][2]) //se for menor fica antes
        return -1;
            
    if (grafo[*x][2] > grafo[*y][2]) //se for maior vem depois
        return 1;

    return 0; //se for igual pode manter como está
}

void UnionTree(No *SubArvores[], int pai[], int x, int y){
    int paizao = pai[y]; //pai(raiz) que será perdido
    
    No *aux = SubArvores[pai[y]]; //ponteiro auxiliar
    
    while(aux->prox != NULL){ //atualizando os pais dos nós da subárvore que será agregada à outra
        int z = aux->prox->n; 
        pai[z] = pai[x];
        
        aux = aux->prox; //continuando o loop
    }
    aux->prox = SubArvores[pai[x]]->prox;
    SubArvores[pai[x]]->prox = SubArvores[paizao]->prox; //unindo as subárvores em uma só
    SubArvores[paizao]->prox = NULL;
    
    SubArvores[pai[x]]->n += SubArvores[paizao]->n; //incrementa a quantidade de nós que cada subárvore possui
    SubArvores[paizao]->n = 0;
    
    return;
}

int Kruskal(int indice[], int numArestas, int numVertices){
    int pai[numVertices]; //vetor que armazena a raiz da subárvore que um nó pertence
    somaAGM = 0; //AGM começa vazia, sem arestas

    No *SubArvores[numVertices]; //Criação das listas encadeadas que contém as subárvores da AGM
    No *galho;

    for(int i=0; i<numVertices; ++i){ //make-Set
        pai[i] = i; //armazena o pai para facilitar na busca
        SubArvores[i] = (No*)malloc(sizeof(No)); //armazena o filho de cada pai para atualizar no Union
        galho = (No*)malloc(sizeof(No)); //alocando novo nó para criar subárvore individual
        
        galho->n = i;
        SubArvores[i]->n = 1; //quantidade de nós que cada subárvore possui
        
        SubArvores[i]->prox = galho; //adicionando nó na subárvore
        galho->prox = NULL;
    }

    for(int i=0; i<numArestas; ++i){
        int x = grafo[indice[i]][0], y = grafo[indice[i]][1]; //vértices pertencentes a aresta a ser analisada
        
        if(pai[x] != pai[y]){ //find-Set: verificando se pertencem à mesma subárvore para não formar ciclos
            if(SubArvores[pai[y]]->n < SubArvores[pai[x]]){ //Union by rank: verificando qual subárvore possui menos nós
                int k = y;
                y = x;
                x = k;
            }
            UnionTree(SubArvores, pai, x, y); //chamando a função para unir as subárvores
            somaAGM += grafo[indice[i]][2]; //incrementa a AGM
        }
    }
    while(SubArvores[pai[0]] != NULL){ //liberando espaço das listas encadeadas
        No *k = SubArvores[pai[0]];
        SubArvores[pai[0]] = SubArvores[pai[0]]->prox;
        free(k);
    }
    for(int i=0; i<numVertices; ++i){ //liberando espaço no vetor das subárvores
        free(SubArvores[i]);
    }
    return somaAGM; 
}

int main(){
    int numVertices, numArestas, economia; //recebendo o número de vértices(junções) e de arestas(estradas)

    while(1){
        scanf("%d %d", &numVertices, &numArestas);

        if(numVertices == 0 && numArestas == 0) //verificando se a entrada é '0 0' para encerrar o programa
            break;
            
        int indice[numArestas]; //o indice será responsável por garantir a ordenação correta das arestas em função do peso
        int somaGrafo = 0; //somando o peso das arestas do grafo e da AGM
      
        for(int i=0; i<numArestas; ++i){
            scanf("%d %d %d", &grafo[i][0], &grafo[i][1], &grafo[i][2]); //recebendo os vértices e peso pertencentes a cada aresta
            indice[i] = i; //o indice irá identificar cada aresta do grafo
            somaGrafo += grafo[i][2]; //somando o valor das arestas do grafo
        }

        qsort(indice, numArestas, sizeof(indice[0]), OrdenaArestas); //utilizando o Quicksort para ordenação da matriz

        somaAGM = Kruskal(indice, numArestas, numVertices); //recebendo a soma das arestas da subárvore
        
        economia = somaGrafo - somaAGM;
        printf("%d\n", economia);
    }
    return EXIT_SUCCESS;
}