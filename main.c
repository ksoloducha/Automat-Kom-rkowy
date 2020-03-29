#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <getopt.h>	//ponieważ program może zostać wywołany z flagami

#include "files.h"
#include "createpng.h"
#include "generation.h"

int XMAX, YMAX;

int main(int argc, char **argv){

	int opt;
	char *inp = "breeder_coordinates.txt";
	int n = 300;
	bool help = false;

	char *usage = 	"Użycie: ./autkom [-f input_file] [-n number_of_generations] [-h] \n\n"
			"	Jeżeli podany jest plik input_file, program czyta z niego początkowe punkty.\n"
			"		W przeciwnym wypadku punkty są czytane z domyślnego pliku breeder_coordinates.txt.\n"
			"	Jeżeli podana jest liczba number_of_generations przeprowadzane jest number_of_generations generacji.\n"
			"		W przeciwnym wypadku przeprowadzane jest 50 generacji.\n"
			"		UWAGA: number_of_generations < 1000\n"
			"	Jeżeli użyta została flaga -h wyświetlana jest instrukcja użycia programu\n";

	/* flagi: [-f input_file] [-n number_of_generations] [-h]  */	
	while ((opt = getopt(argc, argv, "f:n:h")) != -1)

		switch (opt){

			case 'f':
				inp = optarg;
				break;
			case 'n':
				if(atoi(optarg) < 1000)
					n = atoi(optarg);
				else{
					printf("'-n': number_of_generations < 1000\n");
					return 1;
				}
				break;
			case 'h':
				help = true;
				break;
			case '?':
			        if (optopt == 'f' || optopt == 'n')
					fprintf (stderr, "Option -%c requires an argument.\n", optopt);
				else if (isprint (optopt))
					fprintf (stderr, "Unknown option `-%c'.\n", optopt);
			        else
					fprintf (stderr, "Unknown option character `\\x%x'.\n", optopt);
				return 1;
				break;
			default:
				abort();
		}

	if(help){
		printf("%s", usage);
		return 0;
	}

	bool **array = create_tab_from_file(inp);
	if(array == NULL){
		printf("%s: unable to open file with input data\n", inp);
		return 2;
	}
	
	for(int i = 1; i <= n; i++){

		int indx = i;

		char out[7];
		out[0] = '0' + (indx / 100);
		indx %= 100;
		out[1] = '0' + (indx / 10);
		indx %= 10;
		out[2] = '0' + (indx);

		//tworzenie pliku numer_generacji.txt
		out[3] = '.';
		out[4] = 't';
		out[5] = 'x';
		out[6] = 't';		
		print_tab_to_file(array, out);

		//tworzenie pliku numer_generacji.png
		out[4] = 'p';
		out[5] = 'n';
		out[6] = 'g';
		write_png_file(array, out);

		move(array);
	}

	free_tab(array);
	return 0;
}
