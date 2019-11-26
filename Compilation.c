//
//  Compilacion.c
//  
//
//  Created by OCM, DM on 26/11/19.
//

#include "PrimeraParte.h"
#include "TerceraParte.h"
#include "SegundaParte.h"
#include "CuartaParte.h"

int main(){
    printf("Written by Chavez Omar, Mendoza Israel\n\nWelcome\nPara los métodos de:\n 1. Bisección, Newton, Secante y Posición falsa\n 2. Soluciones a sistemas de ecuaciones\n 3. Cholesky\n 4. Metodo de las potencias\n 5. Salir\n ");
    int option;
    scanf("%d", &option);
    if(option==1){
        PrimeraParte();
    }
    else if(option!=1){
        if(option==2){
            SegundaParte();
        }
        else if(option == 3){
            
            printf("Ingresar la dimension de la matriz");
            int n;
            scanf("%d", &n);
            n = abs(n);
              double **matriz[n][n];
              for (int i = 0; i < n; i++)
                {
                  for (int j = 0; j < n; j++){
                      printf("A [%d] [%d]: ", i+1, j+1);
                      scanf("%f", &matriz[i][j]);
                    }
                }
                int mcol = n;
                int ofs = n;
            TerceraParte( **matriz,  n,  **matriz,  mcol, **matriz,  **matriz,  ofs);
        }
        else{
            if(option==4){
                CuartaParte();
            }
        }
    }
    else{
        printf("Gracias por usar el programa. Hasta luego\n");
    }
    return 0;
}
