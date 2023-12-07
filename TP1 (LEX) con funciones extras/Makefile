# How to run: mingw32-make.exe run
# How to test: mingw32-make.exe test
# Add MANUAL=1 to use scanner.c as scanner
# Add BNF=1 to use calculadoraBNF.c as parser

# Default parser is calculadoraPolaca.c
# Default scanner is lex scanner

# Variables
CC = gcc
CFlags = -Wall -Wextra -std=c18
CALCULADORA = calculadoraPolaca.exe
SCANNER_L = scanner.l
STACK_O = stack.o
STACK_C = stack.c
STACK_H = stack.h
RESULTS = results.txt
SCANNER_H = scanner.h
SCANNER_O = scanner.o
SCANNER_AUTO_C = lex.scanner.c
SCANNER_MANUAL_C = scannerManual.c
EXPRESSIONS = expressions.txt
EXPECTED = expected.txt

ifdef OS
   RM = del
	 COMP = comp
	 COMP_M = /M
	 EXECUTE_LINUX = 
else
   ifeq ($(shell uname), Linux)
      RM = rm -f
			COMP = diff
			COMP_M = 
			EXECUTE_LINUX = ./
   endif
endif

ifdef BNF
   CALCULADORA_C = calculadoraBNF.c
   CALCULADORA_O = calculadoraBNF.o
else
    CALCULADORA_C = calculadoraPolaca.c
   	CALCULADORA_O = calculadoraPolaca.o
endif

test: $(CALCULADORA)
	$(EXECUTE_LINUX)$(CALCULADORA) < $(EXPRESSIONS) > $(RESULTS)
	$(COMP) $(EXPECTED) $(RESULTS) $(COMP_M)
	$(RM) $(RESULTS)
	$(RM) $(SCANNER_AUTO_C)
	$(RM) $(CALCULADORA)

run: $(CALCULADORA)
	$(EXECUTE_LINUX)$(CALCULADORA)

$(CALCULADORA): $(CALCULADORA_O) $(SCANNER_O) $(STACK_O)
	$(CC) $(CALCULADORA_O) $(SCANNER_O) $(STACK_O) -lm -o $(CALCULADORA)
	$(RM) $(CALCULADORA_O)
	$(RM) $(SCANNER_O)
	$(RM) $(STACK_O)
 
$(CALCULADORA_O): $(CALCULADORA_C) $(SCANNER_H) $(STACK_H)
	$(CC) $(CFlags) -c $(CALCULADORA_C) -o $(CALCULADORA_O)

ifdef MANUAL
$(SCANNER_O): $(SCANNER_MANUAL_C) $(SCANNER_H)
	$(CC) $(CFlags) -c $(SCANNER_MANUAL_C) -o $(SCANNER_O)
else
$(SCANNER_O): $(SCANNER_L) $(SCANNER_H)
	flex $(SCANNER_L)
	$(CC) $(CFlags) -c $(SCANNER_AUTO_C) -o $(SCANNER_O)
endif

$(STACK_O): $(STACK_C) $(STACK_H)
	$(CC) $(CFlags) -c $(STACK_C)

clean:
	$(RM) $(STACK_O)
	$(RM) $(SCANNER_O)
	$(RM) $(CALCULADORA_O)
	$(RM) $(CALCULADORA)
	$(RM) $(RESULTS)
	$(RM) $(SCANNER_AUTO_C)