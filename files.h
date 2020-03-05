#ifndef _FILE_H_
#define _FILE_H_

/* funkcja tworzy tablicę ze zmiennymi typu bool i zwraca wskaźnik na nią,
 * żywym komórkom, których współrzędne odczytuje z pliku fileName nadaje wartość true,
 * natomiast martwym, false */
bool** create_tab_from_file (char* fileName);
/* funkcja zapisuje żywe komórki z tablicy tab do pliku output_data.txt */
void print_tab_to_file (bool **tab);
/* funkcja zwalnia pamięć po tablicy */
void free_tab (bool **tab);

#endif
