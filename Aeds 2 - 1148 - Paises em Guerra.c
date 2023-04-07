//1148 - Países em Guerra
//Problema de muitos pra muitos: será utilizado o algoritmo de Floyd-Warshall

#include <stdio.h>
#include <stdlib.h>

#define N 500 //quantidade máxima de vértices

void Floyd_Warshall(int matrizAdj[][N], int numVertices){
    for(int k=0; k<numVertices; ++k){ //inicializando a matriz de adjacencia e de predecessores
            for(int i=0; i<numVertices; ++i){
                for(int j=0; j<numVertices; ++j){
                    if(matrizAdj[i][j] > matrizAdj[i][k] + matrizAdj[k][j]){
                        matrizAdj[i][j] = matrizAdj[i][k] + matrizAdj[k][j];
                    }
                }
            }   
        }
    
    return;
}

void InicializaMatriz(int matrizAdj[][N], int numVertices){
    for(int i=0; i<numVertices; ++i){ //inicializando a matriz de adjacencia
        for(int j=0; j<numVertices; ++j){
            matrizAdj[i][j] = 10000000;
        }
        matrizAdj[i][i] = 0;        
    }
    return;
}

void PreencheMatriz(int matrizAdj[][N], int numVertices, int v1, int v2, int peso){
    if(matrizAdj[v2-1][v1-1] < 10000000){
        matrizAdj[v1-1][v2-1] = 0;
        matrizAdj[v2-1][v1-1] = 0;
    }
    else{
        matrizAdj[v1-1][v2-1] = peso;
    }  
    
    return;
}

int main(){
    int numVertices, numArestas; //recebendo o número de vértices(cidades) e de arestas(acordos)

    while(1){
        scanf("%d %d", &numVertices, &numArestas);

        if(numVertices == 0 && numArestas == 0) //verificando se a entrada é '0 0' para encerrar o programa
            break;

        int v1, v2, peso, matrizAdj[N][N]; //recebendo o conjunto de vértices e de arestas para criação da Matriz de Adjacencia

        InicializaMatriz(matrizAdj, numVertices); //inicializando a matriz de adjacencia
        
            
        for(int i=0; i<numArestas; ++i){
            scanf("%d %d %d", &v1, &v2, &peso);
            PreencheMatriz(matrizAdj, numVertices, v1, v2, peso); //Preenchendo a matriz com os pesos
        }

        Floyd_Warshall(matrizAdj, numVertices); //chamando a função do Floyd-Warshall

        int numConsultas;
        scanf("%d", &numConsultas); //numero de consultas a serem realizadas

        int x1, x2; //colhendo os vértices a serem consultados
        for(int i=0; i<numConsultas; ++i){
            scanf("%d %d", &x1, &x2);

            if(matrizAdj[x1-1][x2-1] < 1000000){
                printf("%d\n", matrizAdj[x1-1][x2-1]);
            }
   
            else{
                printf("Nao e possivel entregar a carta\n");
            }
        }
        printf("\n");
    }
    return EXIT_SUCCESS;
}