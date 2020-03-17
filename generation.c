#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "generation.h"
estern int XMAX, YMAX;

void move (bool **array){
  // tymczasowa tablica ze stanami początkowymi
  bool temp[XMAX][YMAX];
  for (int i = 0; i < XMAX; i++ ){
    for (int j = 0; j < YMAX; j++ ){
      temp[i][j] = array[i][j];
    }
  }

  int neighbors;
  for (int i = 0; i < XMAX; i++ ){
    for (int j = 0; j < YMAX; j++ ){
      
      neighbors = 0;
      
      for(int x = i - 1; x <= i + 1; x++)
				for(int y = j - 1; y <= j + 1; y++){

					if(x < 0 || x == XMAX || y < 0 || y == YMAX)
						continue;

					else if(tmp[x][y])
						neighbors++;
				}
			if(!tmp[i][j] && neighbors == 3)
				array[i][j] = true;
			else if(tmp[i][j] && neighbors != 3 && neighbors != 4)
				array[i][j] = false;
      
    }
  }
}
