#ifndef _GENERATION_H_
#define _GENERATION_H_

/* program ma na celu modyfikować tablice typu bool w taki sposób, że:
 * martwe komórki posiadajace co najmniej 3 żywych sasiadów stają się żywe,
 * żywe komórki są dalej żywe tylko wtedy gdy mają 2 lub 3 sąsiadów,
 * w innych wypadkach stają się martwe  */

/* funkcja przyjmuje wskaźnik na oryginalną tablice i tworzy tymczasowa w celu
 * zapamiętania początkowego układu komórek, modyfikuje oryginalną tablice
 * według reguły powyżej  */
void move (bool **tab);

#endif
