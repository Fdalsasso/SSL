#include <stdio.h>
#include "Conversion.h"

int main(){
    double cotaI, cotaS, salto;
    printf("Ingrese el primer valor de la tabla\n");
    fflush(stdout);
    scanf("%lf", &cotaI);
    printf("Ingrese el ultimo valor de la tabla\n");
    fflush(stdout);
    scanf("%lf", &cotaS);
    printf("Ingrese los valores de los saltos de la tabla\n");
    fflush(stdout);
    scanf("%lf", &salto);
    PrintTablas(cotaI, cotaS, salto);
}

void PrintTablas (double cotaI, double cotaS, double salto){
    PrintTablaCelsius(cotaI, cotaS, salto);
    printf("\n");
    PrintTablaFahrenheit(cotaI, cotaS, salto);
}  

void PrintTablaCelsius (double cotaI, double cotaS, double salto){
    printf("Tabla de Farenheit a Celsius\n\n");
    PrintFilas(cotaI, cotaS, salto, Celsius);
}

void PrintTablaFahrenheit (double cotaI, double cotaS, double salto){
    printf("Tabla de Celsius a Farenheit\n\n");
    PrintFilas(cotaI, cotaS, salto, Farenheit);
}

void PrintFilas (double cotaI, double cotaS, double salto, double (*conversion)()){
    for(double cont = cotaI; cont <= cotaS; cont += salto){
        PrintFila(cont, conversion);
    }
}

void PrintFila (double temp, double (*conversion)()){
    printf("%.2lf\t%.2lf\n", temp, conversion(temp));
}