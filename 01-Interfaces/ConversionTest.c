#include <assert.h>
#include "Conversion.h"

void main(){
    const double delta = 0.00000001;
    const double conversionCelsius = Celsius(37) - 2.7777777777;
    const double conversionFarenheit = Farenheit(0.356169) - 32.6411042;

assert(Celsius(32) == 0);
assert(Farenheit(0) == 32);
assert(conversionCelsius < delta);
assert(conversionFarenheit < delta);
}