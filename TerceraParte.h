#include <math.h>
#include <stdio.h>
#include <stdlib.h>


void TerceraParte(double **orig, int n, double **aug, int mcol,double **chol, double **cholaug, int ofs){
   int i, j, k, l;
   int retval = 1;

   for (i=ofs; i<n+ofs; i++) {
      chol[i][i] = orig[i][i];
      for (k=ofs; k<i; k++)
     chol[i][i] -= chol[k][i]*chol[k][i];
      if (chol[i][i] <= 0) {
     fprintf(stderr,"\nERROR No es EDD\n");
     printf("\nRevisar --->>> %d %f\n",i,chol[i][i]);
     retval = 0;
     //return retval;
      }
      chol[i][i] = sqrt(chol[i][i]);

      for (l=ofs; l<mcol+ofs; l++) {
     cholaug[i][l] = aug[i][l];
     for (k=ofs; k<i; k++) {
        cholaug[i][l] -= cholaug[k][l]*chol[k][i];
     }
     cholaug[i][l] /= chol[i][i];
      }

      for (j=i+1; j<n+ofs; j++) {
     chol[i][j] = orig[i][j];
     for (k=ofs; k<i; k++)
        chol[i][j] -= chol[k][i]*chol[k][j];
     chol[i][j] /= chol[i][i];
      }
   }

   printf("%d\n", retval);
}
      
