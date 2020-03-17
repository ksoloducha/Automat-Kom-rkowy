#ifndef _FILES_H_
#define _FILES_H_

/* program obsługuje pliki w formacie:
 * "wymiar_x_okna_graficznego	wymiar_y_okna_graficznego
 * x_1	y_1
 * x_2	y_2
 * ...
 * x_n	y_n" */

/* funkcja tworzy tablicę ze zmiennymi typu bool i zwraca wskaźnik na nią,
 * żywym komórkom, których współrzędne odczytuje z pliku fileName nadaje wartość true,
 * natomiast martwym, false */
bool** create_tab_from_file (char* fileName);
/* funkcja zapisuje żywe komórki z tablicy tab do pliku output_data.txt */
void print_tab_to_file (bool **tab, char *filename);
/* funkcja zwalnia pamięć po tablicy */
void free_tab (bool **tab);

#endif
