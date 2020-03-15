#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

estern int XMAX, YMAX;

void move (bool **tab){
  // tymczasowa tablica ze stanami początkowymi
  bool temp[XMAX][YMAX];
  for (int i = 0; i < XMAX; i++ ){
    for (int j = 0; j < YMAX; j++ ){
      temp[i][j] = tab[i][j];
    }
  }

  int neighbors;
  for (int i = 0; i < XMAX; i++ ){
    for (int j = 0; j < YMAX; j++ ){
      neighbors = 0;
      // pierwszy wiersz
      if (j == 0){
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
        // 1. krawedz   [0][0]
        if (i == 0) {
          if (temp[i+1][j])
            neighbors++;
          if (temp[i+1][j+1])
            neighbors++;
          if (temp[i][j+1])
            neighbors++;
        }
        // 2. krawedz   [XMAX][0]
        if (i == XMAX-1){
          if (temp[i-1][j])
            neighbors++;
          if (temp[i-1][j+1])
            neighbors++;
          if (temp[i][j+1])
            neighbors++;
        }
      }
      // wiersze wewnetrzne
      if (j > 0 && j < YMAX-1){
        // pierwsza kolumna
        if (i == 0){
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
        // komorki wewnetrzne
        if (i > 0 && i < XMAX-1){
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
        // ostatnia kolumna
        if (i == XMAX-1){
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
      // ostatni wiersz
      if (j == YMAX-1){
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
        // 3. krawedz   [0][YMAX]
        if (i == 0){
          if (temp[i][j-1])
            neighbors++;
          if (temp[i+1][j-1])
            neighbors++;
          if (temp[i+1][j])
            neighbors++;
        }
        // 4. krawedz   [XMAX][YMAX]
        if (i == XMAX-1){
          if (temp[i-1][j])
            neighbors++;
          if (temp[i-1][j-1])
            neighbors++;
          if (temp[i][j-1])
            neighbors++;
        }
      }
      // martwa komórka ma co najmniej 3 sąsiadów - staje się żywa
      if (neighbors >= 3 && temp[i][j] == false)
        tab[i][j] = true;
      // żywa komórka nie ma 2 lub 3 sąsiadów - staje sie martwa
      if ((neighbors < 2 || neighbors > 3) && temp[i][j] == true)
        tab[i][j] = false;
    }
  }
}
