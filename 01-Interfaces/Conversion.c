#include "Conversion.h"

double Celsius (double farenheit){
    return (farenheit - 32) * 5.0 / 9.0;
}

double Farenheit (double celsius){
    return (celsius * 9.0 /5.0) + 32;
}