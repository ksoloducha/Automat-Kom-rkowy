LIBS += -lpng

autkom: main.o createpng.o files.o generation.o
	cc -o autkom main.o createpng.o files.o generation.o $(LIBS)

main.o: main.c
	cc -c main.c
files.o: files.c files.h
	cc -c files.c
createpng.o: createpng.c createpng.h
	cc -c createpng.c
generation.o: generation.c generation.h
	cc -c generation.c

.PHONY: clean

clean:
	-rm *.o
