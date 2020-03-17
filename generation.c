#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "generation.h"

//zadeklarowane w funkcji main
extern int XMAX, YMAX;

void move (bool **array){
	
  // tymczasowa tablica ze stanami początkowymi
  bool tmp[XMAX][YMAX];
  for (int i = 0; i < XMAX; i++ )
    for (int j = 0; j < YMAX; j++ )
      tmp[i][j] = array[i][j];

  int neighbors;	//licznik żywych są siadów badanej komórki
	
  for (int i = 0; i < XMAX; i++ ){
    for (int j = 0; j < YMAX; j++ ){
      
      neighbors = 0;
      
	//sprawdzenie ośmiu sąsiadów oraz rozpatrywanej komórki
      for(int x = i - 1; x <= i + 1; x++)
		for(int y = j - 1; y <= j + 1; y++){

			/* jeżeli indeksy wyjdą poza tablicę, badane są kolejne komórki,
			** ponieważ nieistniejący sąsiedzi sa uznawani za martwych */
			if(x < 0 || x == XMAX || y < 0 || y == YMAX)
				continue;

			else if(tmp[x][y])
				neighbors++;
		}
	    
	    	/* sprawdzane są jedynie przypadki, w których należy zmienić stan komórki, tj:
		* 	- Martwa komórka, która ma dokładnie 3 żywych sąsiadów,
		* 	  staje się żywa w następnej jednostce czasu (rodzi się)
		* 	- Żywa komórka z 2 albo 3 żywymi sąsiadami pozostaje nadal żywa;
		* 	  przy innej liczbie sąsiadów umiera (z "samotności" albo "zatłoczenia"). */
		if(!tmp[i][j] && neighbors == 3)
			array[i][j] = true;
	    	/* porównywanie do 3 i 4, a nie 2 i 3, ponieważ jeśli komórka jest żywa została "dodana"
		** do swoich żywych sąsiadów */
		else if(tmp[i][j] && neighbors != 3 && neighbors != 4)
			array[i][j] = false;
    }
  }
}
