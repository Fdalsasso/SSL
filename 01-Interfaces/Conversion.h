#ifndef Conversion_h
#define Conversion_h

void PrintTablas (double cotaI, double cotaS, double salto);
void PrintTablaCelsius (double cotaI, double cotaS, double salto);
void PrintTablaFahrenheit (double cotaI, double cotaS, double salto);
void PrintFilas (double cotaI, double cotaS, double salto, double (*conversion)());
void PrintFila (double temp, double (*conversion)());
double Celsius (double farenheit);
double Farenheit (double celsius);

#endif