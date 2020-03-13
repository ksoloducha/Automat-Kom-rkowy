#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

extern int XMAX, YMAX;

bool** create_tab_from_file (char* fileName){

	FILE *in = fopen (fileName, "r");

	if(in == NULL)
		return NULL;

	fscanf(in, "%d %d", &XMAX, &YMAX);

	bool **myTab = (bool**) malloc (XMAX * sizeof (bool*));
	for(int i = 0; i < XMAX; i++)
		myTab[i] = (bool*) malloc (YMAX * sizeof (bool));

	for(int i = 0; i < XMAX; i++)
		for(int j = 0; j < YMAX; j++)
			myTab[i][j] = false;

	int x, y;

	while(fscanf(in, "%d", &x) == 1 && fscanf(in, "%d", &y) == 1 )
		myTab[x][y] = true;

	fclose(in);
	return myTab;
}

void print_tab_to_file (bool **tab, char *filename){
<<<<<<< HEAD

	FILE *out = fopen (filename, "w");	

=======

	FILE *out = fopen(filename, "w");
	
>>>>>>> d02f1e7b6905a41c76f238232aaddc8d50d7ef1a
	fprintf(out, "%d\t%d\n", XMAX, YMAX);

	for(int i = 0; i < XMAX; i++)
		for(int j = 0; j < YMAX; j++)
			if(tab[i][j])
				fprintf(out,"%d\t%d\n", i, j);

	fclose(out);
}

void free_tab (bool **tab){

	for(int i = 0; i < XMAX; i++)
		free(tab[i]);
	free(tab);
}
