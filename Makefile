FONTES = pilha.c  matriz.c main.c
OBJETOS = $(FONTES:.c=.o)

all: main

main : $(OBJETOS)
	gcc $(OBJETOS) -o main

$(OBJETOS) : $(FONTES)
	gcc -c $(FONTES)

clean :
	-@ rm -f $(OBJETOS)
