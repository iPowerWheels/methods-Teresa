#include <stdio.h>
#include <stdlib.h>

int determinantes(long double A[100][100], int n)
{
    long double Minor[100][100];
    int i,j,k,c1,c2;
    int determinant;
    int c[100];
    int O=1;

    if(n == 2)
    {
        determinant = 0;
        determinant = (A[0][0]*A[1][1])-(A[0][1]*A[1][0]);
        return determinant;
    }
    else
    {
        for(i = 0 ; i < n ; i++)
        {
            c1 = 0, c2 = 0;
            for(j = 0 ; j < n ; j++)
            {
                for(k = 0 ; k < n ; k++)
                {
                    if(j != 0 && k != i)
                    {
                        Minor[c1][c2] = A[j][k];
                        c2++;
                        if(c2>n-2)
                        {
                            c1++;
                            c2=0;
                        }
                    }
                }
            }
            determinant = determinant + O*(A[0][i]*determinantes(Minor,n-1));
            O=-1*O;
        }
    }
    return determinant;
}

int SegundaParte(void) {
MainMenu:
  printf("Bienvenido\nSolución de sistema de ecuaciones\n Ingresar la dimension de su matriz [0 para salir]: ");
  int dimension;
  scanf("%d", &dimension);
  dimension = abs(dimension);
  if(dimension>0) {
    long double matriz[dimension][dimension];
    for (int i = 0; i < dimension; i++)
      {
        for (int j = 0; j < dimension; j++)
          {
            printf("Ingresar el valor de la matriz en la posición %d, %d: ", i+1, j+1);
            scanf("%LF", &matriz[i][j]);
          }
      }
    int determinante;
    determinante = determinantes(matriz, dimension);
    printf("El determinante de su matriz es: %d\n", determinante);
    if(determinante!=0) {
      printf("Se puede intentar hacer una solución\n");
      long double mayor, tolerancia;
      int col_position, row_position, iteraciones;
      for (int i = 0; i < dimension; i++)
        {
          for (int j = 0; i < dimension; i++)
            {
              if(mayor<matriz[i][j]){
                mayor = matriz[i][j];
                col_position = j;
                row_position = i;
                iteraciones = 0;
                if(row_position!=col_position){
                  printf("Se encontró una discrepancia en su matriz, no se garantiza la convergencia\nIngrese el número máximo de iteraciones: ");
                  scanf("%d", &iteraciones);
                  printf("Ingrese el valor de tolerancia requerido: ");
                  scanf("%LF", &tolerancia);
                }
              }
            }
        }
      long double vector[dimension];
      printf("Ingresar el vector independiente \n");
      for (int i = 0; i < dimension; i++)
        {
          scanf("%LF", &vector[i]);
        }
      if(iteraciones==0) {
        int iteration;
        long double resultado[dimension];
        for (int i = 0; i < dimension; i++)
          {
            iteration = i;
            resultado[i] = 0;
          }
        for (int i = 0; i < dimension; i++)
          {
            for (int j = 0; i < dimension; i++)
              {
                resultado[i] = (vector[i]/matriz[i][i]) - (matriz[i][j]/matriz[i][i]);
              }
            printf("%LF\n", resultado[i]);
          }
      }
    }
    else {
      printf("Imposible realizar la acción\nReturning Main Menu\n");
      goto MainMenu;
    }
  }
  else if(dimension==0) {
    printf("Hasta luego.\n");
    return 1;
  }
  else {
    printf("WARNING!\nCritical error\nPlease restart\n\a");
    return 2;
  }
  return 0;
}
