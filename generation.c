#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

estern int XMAX, YMAX;

void move (bool **tab){
  bool temp[XMAX][YMAX];

  for (int i = 0; i < XMAX; i++ ){   // tymczasowa tablica ze stanem poczatkowym
    for (int j = 0; j < YMAX; j++ ){
      temp[i][j] = tab[i][j];
    }
  }

  int neighbors;
  for (int i = 0; i < XMAX; i++ ){
    for (int j = 0; j < YMAX; j++ ){
      neighbors = 0;  // ilosc sasiadow

      if (temp[i][j] == false){  // jesli martwa ma conajmniej 3
                                 // zywych sasiadow staje sie zywa
        if (j == 0){  // pierwszy wiersz
          if (i != 0 && i != XMAX-1){
            if (temp[i-1][j])
              neighbors++;
            if (temp[i-1][j+1])
              neighbors++;
            if (temp[i][j+1])
              neighbors++;
            if (temp[i+1][j+1])
              neighbors++;
            if (temp[i+1][j])
              neighbors++;
          }
          if (i == 0) {  // 1. krawedz  [0][0]
            if (temp[i+1][j] && temp[i+1][j+1] && temp[i][j+1])
              neighbors += 3;
          }
          if (i == XMAX-1){  // 2. krawedz  [XMAX][0]
            if (temp[i-1][j] && temp[i-1][j+1] && temp[i][j+1])
              neighbors += 3;
          }
        }

        if (j > 0 && j < YMAX-1){  // wiersze wewnetrzne
          if (i == 0){  // pierwsza kolumna
            if (temp[i][j-1])
              neighbors++;
            if (temp[i+1][j-1])
              neighbors++;
            if (temp[i+1][j])
              neighbors++;
            if (temp[i+1][j+1])
              neighbors++;
            if (temp[i][j+1])
              neighbors++;
          }
          if (i > 0 && i < XMAX-1){  // komorki wewnetrzne
            if (temp[i-1][j-1])
              neighbors++;
            if (temp[i][j-1])
              neighbors++;
            if (temp[i+1][j-1])
              neighbors++;
            if (temp[i+1][j])
              neighbors++;
            if (temp[i+1][j+1])
              neighbors++;
            if (temp[i][j+1])
              neighbors++;
            if (temp[i-1][j+1])
              neighbors++;
            if (temp[i-1][j])
              neighbors++;
          }

          if (i == XMAX-1){  // ostatnia kolumna
            if (temp[i][j-1])
              neighbors++;
            if (temp[i-1][j-1])
              neighbors++;
            if (temp[i-1][j])
              neighbors++;
            if (temp[i-1][j+1])
              neighbors++;
            if (temp[i][j+1])
              neighbors++;
          }
        }

        if (j == YMAX-1){  // ostatni wiersz
          if (i != 0 && i != XMAX-1){
            if (temp[i-1][j])
              neighbors++;
            if (temp[i-1][j-1])
              neighbors++;
            if (temp[i][j-1])
              neighbors++;
            if (temp[i+1][j-1])
              neighbors++;
            if (temp[i+1][j])
              neighbors++;
          }
          if (i == 0){  // 3. krawedz   [0][YMAX]
            if (temp[i][j-1] && temp[i+1][j-1] && temp[i+1][j])
              neighbors += 3;
          }
          if (i == XMAX-1){ // 4. krawedz    [XMAX][YMAX]
            if (temp[i-1][j] && temp[i-1][j-1] && temp[i][j-1])
              neighbors += 3;
          }
        }
      }
      if (neighbors >=3)
        tab[i][j] = true;

      if (temp[i][j] == true){


      }

    }
  }

}
