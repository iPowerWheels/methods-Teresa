//
//  Naucalpan - 2019 (C)
//
//
//  Written by Arellano, Chavez, Mendoza...
//

#include<stdio.h>
#include<math.h>
#include <stdlib.h>

//Se hacen las declaraciones para las funciones
double f1(long double x) {
    return (x*x)*cos(x)-(2*x);
}

double f2(long double x) {
    return ((7.3-4/x*x)*exp(x*-1)/4)-1.5;
}

double f3(long double x) {
    return pow(x,3)-(3*sin(x*x))+1;
}

double f4(long double x) {
    return pow(x,3) + (6*x*x) + (9.4*x) + 2.5;
}

//Secuencia de instrucciones que se encargan de realizar las operaciones en las funciones
double funciones(int selection, long double x){
    switch(selection) {
        case 1:{
            return f1(x);
            break;
        }

        case 2: {
            return f2(x);
            break;
        }

        case 3: {
            return f3(x);
            break;
        }

        case 4: {
            return f4(x);
            break;
        }
    }
}

double derivated_function (long double x, int choosen) {
    switch(choosen) {
        case 1:{
            return -2.0 + (2.0*x*cos(x)) - (x*x*sin(x));
            break;
        }

        case 2: {
            return 12/(pow(x, 4));
            break;
        }

        case 3: {
            return (3.0 * x) * (x - (2.0 * cos(x*x)));
            break;
        }

        case 4: {
            return 9.4 + (12*x) + (3.0*x*x);
            break;
        }
    }
}
//Declaracion de cada metodo
double secante(int funcion) {
    double x0 = 0, x1 = 10;

    int decimales = 8, maximo = 50;

    double aux;

    aux = (decimales > 0) ? 1/pow(10,decimales) : pow(10,decimales);

    double aux2;

    double x2= x1-funciones(funcion, x1)*(x0-x1)/(funciones(funcion, x0)-funciones(funcion, x1));

    int i=0;

    do {
        printf("\nI= %d \t x0= %.10f \t x1= %.10f \t x2= %.10f \t f(x2)= %.10f \n",i,x0,x1,x2,funciones(funcion, x2));

        x0 = x1;

        x1 = x2;

        x2= x1-funciones(funcion, x1)*(x0-x1)/(funciones(funcion, x0)-funciones(funcion, x1));

        i++;

        aux2 = (funciones(funcion, x2)>0) ? funciones(funcion, x2) : -1*funciones(funcion, x2);
    } while(abs(aux2>aux)&&(i<maximo));
    
    printf("\nI= %d \t x0= %.10f \t x1= %.10f \t x2= %.10f \t f(x2)= %.10f \n",i,x0,x1,x2,funciones(x2,funcion));

    if(funciones(funcion, x2)<1 && funciones(funcion, x2)>-1) {
        return x2;
    }
    else{
        printf("\n \t \tINTENTA CON OTRO INTERVALO \n ");
        return 0;
    }
}

double PosicionFalsa(int equation){
double x0, x1, fx0, fx1, x2, fx2, tol, it;
    printf("== Metodo de Posicion Falsa == \n\n");
        start:
    printf("Elegir los intervalos que van a iterar sobre la funcion\n");
        printf (" Intervalo 1 :");
                scanf("%lf", &x0);
        printf (" Intervalo 2 :");
                scanf("%lf", &x1);
            
    printf("Seleccionar el numero de iteraciones\n Iteraciones:");
        scanf("%lf", &it);

    printf("Ingresar tolerancia:\n Tolerancia:");
        scanf("%lf",&tol);

    if(funciones(equation,x0) < funciones(equation,x1)){
        printf("Creando tabla... \n");
        system("sleep 1");
        
        //generando bucle de iteraciones
        for(int n=1; n<=it; n++){
        
            printf("\n iteracion: %d\t",n);
            
            printf("x0 = %.10f \t x1 = %.10f \t",x0,x1);
        
                fx0 = funciones(equation, x0);
                    printf("F(x0) = %.10f \t",fx0);
        
                fx1 = funciones(equation, x1);
                    printf("F(x1) = %.10f \t",fx1);
        
                x2 = x0-fx0*((x1-x0)/(fx1-fx0));
                    printf("x2 = %.10f \t",x2);
        
                fx2 = funciones(equation, x2);
                    printf("F(x2) = %.10f \t\n",fx2);
            
                if(fx2 < fx0){
                    x0=x2;
                    fx0=fx2;
                }
                else if(fx2 > fx0){
                    x1=x2;
                    fx1=fx2;
                }
                else{
                    printf("Raiz no encontrada...");
                }//else
        }//close for
        printf("\n");
    }//close if
    else{
        printf("Error \n\t NOTA:Los las funciones de los intervalos F(intervalo n) tienen que ser de signos opuestos \n\n");
            goto start;
        }
        printf("La aproximacion a la raiz es: %lf \n\n",x2);
return 0;
}//close PosicionFalsa

int newton (int equation) {
    printf("Ingresar el punto inicial (aproximado a la ra-z): ");

    long double xi;

    scanf("%LF", &xi);

    printf("Ingresar el m-ximo de iteraciones: ");

    int iterations;

    scanf("%d", &iterations);

    printf("Ingresar tolerancia requerida: ");

    long double tolerance;

    scanf("%LF", &tolerance);

    long double f_xi, df_xi, xi_before, relative_error;

    for (int n = 1; n <= iterations; n++) {
        if (df_xi != 0) {
            f_xi = funciones(equation, xi);

            df_xi = derivated_function(xi, equation);

            printf("%06.10LF    %06.10LF    %06.10LF\n", xi, f_xi, df_xi);

            xi_before = xi;

            xi = (f_xi/df_xi);

            relative_error = (xi - xi_before)/xi;
        }
        else
            printf("WARNING!\nEl valor de la derivada se volvi- cero\n");
    }
    if (tolerance < relative_error)
        printf("\nEl valor aproximado a la ra-z es: %6.10LF.\nCon una tolerancia de %1.8LF\n", xi, relative_error);

    else
        printf("\nEl valor aproximado a la ra-z es: %6.10LF.\n", xi);
    return 0;
}

int bisection (int equation) {
    long double a, b, f_a, f_b, p, f_p;

    Begin:

    printf("Ingresar el valor inicial para el intervalo: ");

    scanf("%LF", &a);

    printf("Ingresar el valor final del intervalo: ");

    scanf("%LF", &b);

    printf("Ingresar el n-mero de iteraciones deseadas: ");

    int numero_de_iteraciones;

    scanf("%d", &numero_de_iteraciones);

    if ((funciones (equation, a)) * (funciones (equation, b)) < 0){
        for (int i = 0; i < numero_de_iteraciones; i++) {
            f_a = funciones (equation, a);

            f_b = funciones (equation, b);

            p = (a + b) / 2;

            f_p = funciones (equation, p);

            printf("%LF    %LF    %LF    %LF    %LF    %LF\n", a, b, f_a, f_b, p, f_p);

            if (f_p < 0){
                a = p;

                f_a = f_p;

                printf("Aproximaci-n a la ra-z: %LF\r", p);
            }
            else if (f_p > 0){
                b = p;

                f_b = f_p;

                printf("Aproximaci-n a la ra-z: %LF\r", p);
            }
            else
                printf("Usted ha encontrado la ra-z: %LF\n", p);
        };
        printf("\n");
    }
    else {
        printf ("Usted debe seleccionar otro intervalo\n");

        goto Begin;
    }
    return 0;
}

void PrimeraParte (void) {

    printf("\n Metodos numericos 1\n Resoluci-n de ecuaci-nes a trav-s de 4 m-todos\n\n");

    Title:

        printf("\n Bienvenidx, a continuacion podr- escoger el m-todo con el que desea trabajar:\n\n");

        printf("-seleccione-\n 1. Biseccion\n 2. Posici-n falsa\n 3. Newton\n 4. Secante\n 5. Salir\n  Opcion:");

        int choose_method;

        scanf("%d", &choose_method);

        if (choose_method != 5) {

            printf ("\n\n Las posibles funciones a operar son las siguientes:\n  1- f(x) = x² cos x - 2x\n  2- f(x) = 7.3 - 4 / x² * x⁻¹\n  3- x³ - 3 sin x² - 1\n  4- f(x) = x³ + 6x² + 9.4x + 2.5\n ");
                printf("\n Opcion:");
            int choose_eq;

            scanf("%d", &choose_eq);

            switch (choose_method) {
                case 1: {
                    bisection(choose_eq);

                    goto Title;

                    break;
                }

                case 2: {
                    PosicionFalsa(choose_eq);

                    goto Title;

                    break;
                }

                case 3: {
                    newton(choose_eq);

                    goto Title;

                    break;
                }

                case 4: {
                    secante(choose_eq);

                    goto Title;

                    break;
                }

                case 5: {
                    printf("Gracias\n...\n");

                    break;
                }

                default: {
                    system("sleep 3");

                    printf("\aFatal Error!\nInvalid option\nTry again\n");

                    goto Title;

                    break;
                }
            }
        }
        else
        fin:
            printf("\n Gracias\n\n ...\n");
}
