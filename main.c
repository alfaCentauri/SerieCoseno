/* 
 * File:   main.c
 * Author: Ing. Ricardo Presilla
 *
 * Created on 28 de noviembre de 2016, 04:46 PM
 * Programa en C para calcular la Serie del Coseno.
 */

#include <stdlib.h>
#include <stdio.h>
#define MAX 1000
/*Definición de funciones*/
void evaluapoli(int n, double *f, double x);
double factorial(int n);
double potencia(double x, int y);
/**Variables globales**/
double p=0; //p es el valor del polinomio en el punto x
/**Cuerpo del programa.*/
int main(){
    system("clear");
    int i, n=0, prod = -1;
    double f[MAX]; // Define el arreglo para los valores de los coeficientes del polinomio
    float x; //Valor ha evaluar con la serie del coseno
    double coseno=0;
    //Introduce el grado del polinomio
    printf("Aproximacion polinomica para el coseno (grado) = ? ");
    scanf("%d",&n); 
    // Se generan los coeficientes del polinomio
    for (i = 0; i <= n; i++) {      
        f[i] = potencia(-1,i) * (1/factorial(2*i));
    }
/* Se suman los coeficientes de los polinomios */
    for (i = 0; i < n; i++) {  
        coseno+=f[i];
        printf("f[%d] = %.4f\n",i,f[i]);
    }
    printf("\nEl coseno será evaluado en el punto (radianes)\n\nX = ? ");
    // Se introduce el valor de x
    scanf("%f",&x); 
    printf("\nEl valor de x= %f\n",x);
    /*Se calcula la serie con el valor de x*/
    for (i = 0; i <= n; i++) {      
        f[i] = potencia(-1,i) * (potencia(x,2*i)/factorial(2*i));
    }
    /* Esta es la función que evalua el polinomio en el punto x. Evita el uso 
     * de una fórmula con la función pow de la libreria math.h */
    evaluapoli(n, f, x);
    printf("Cos(%f) = %f \n",x,coseno);
    printf("p = %9.4f\n",p); 
    return 0; 
}
/**Método para evaluar el polinomio.
 * @param n Tipo entero.
 * @param f Apuntador tipo double.
 * @param x Tipo double.
 * @param p Dirección de memoria de la variable p.
 **/ 
void evaluapoli(int n, double *f, double x){
    int i;  
    double a[n];
    for (i = 0; i <= n; i+=2) {  // Crea una copia de los elementos de f[i]
        a[i] = f[i];        // porque el ciclo for inferior los destruye       
    }   
    for (i = n; i > 0; i--) {
        p = a[i] * x + a[i - 1];
        a[i - 1] = p;
    } // P es el valor del polinomio en el punto x
}
/**Método para calcular un factorial de n.
 * @param n Tipo entero.
 */ 
double factorial(int n){ 
    int i;     
    double factor = 1;
    for (i = n; i >= 1; i--)
        factor *= i;
    return factor;  
}
/**Potencia de un número**/
double potencia(double x, int y){
    int i;
    double pot=1;
    for(i=0; i<y; i++){
        pot*=x;
    }
    return pot;
}