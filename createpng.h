#ifndef _CREATEPNG_H_
#define _CREATEPNG_H_

/* funkcja tworząca plik png z przygotowanych wcześniej danych */
void write_png_file(char* file_name);
/* funkcja czytająca dane z tabeli bool przekazywanej jako argument
 * oraz przygotowująca z nich dane do stworzenia pliku png */
void process_arr(bool **array);

#endif
