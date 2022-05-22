all : TablasDeConversion.exe

test : ConversionTest.exe

CFLAGS = -Wall -Wextra -std=c18

TablasDeConversion.exe : Conversion.o TablasDeConversion.o
	gcc  -o TablasDeConversion.exe Conversion.o TablasDeConversion.o

TablasDeConversion.o : Conversion.h TablasDeConversion.c
	gcc $(CFLAGS) -c TablasDeConversion.c

Conversion.o : Conversion.c Conversion.h
	gcc $(CFLAGS) -c Conversion.c

ConversionTest.exe : Conversion.o ConversionTest.o
	gcc -o ConversionTest.exe Conversion.o ConversionTest.o

ConversionTest.o : ConversionTest.c Conversion.h
	gcc $(CFLAGS) -c ConversionTest.c

clean:
	rm -f TablasDeConversion
	rm -f TablasDeConversion.o
	rm -f Conversion.o
	rm -f ConversionTest
	rm -f ConversionTest.o
