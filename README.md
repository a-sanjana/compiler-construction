# compiler-construction

## Compilation intructions for ast and symbol table:

$ lex pascal.l

$ yacc -d remove_extra.y

$ gcc -c ast.c -o ast.o

$ gcc -c sym.c -o sym.o

$ gcc -c output.c -o output.o

$ gcc lex.yy.c y.tab.c ast.o sym.o output.o -o parser -ll -lm\

$ ./parser < input_filename.pas

## Compilation intructions for 3AC code:

$ lex pascal.l

$ yacc -d remove_extra.y

$ gcc lex.yy.c y.tab.c -o parser -ll

$ ./parser < input_filename.pas

## Compilation intructions for output:

$ lex pascal.l

$ yacc -d remove_extra.y

$ gcc -c ast.c -o ast.o

$ gcc -c sym.c -o sym.o

$ gcc -c output.c -o output.o

$ gcc lex.yy.c y.tab.c ast.o sym.o output.o -o parser -ll -lm

$ ./parser < input_filename.pas
