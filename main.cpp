#include <iostream>
#include "Spreadsheet.h"

using namespace std;

int main(){

    //testy poprawnego działania programu

    Spreadsheet arkusz;
    
//sprawdzanie działania odczytu z pliku, równoczesne tworzenie arkusza w programie do edycji
    
    arkusz.odczytzpliku("dane.txt");

    arkusz.printout();

    cout << endl << endl;
    
//sprawdzanie usuwania zawartości
    
    arkusz.clearCell(2, 3);

    arkusz.printout();

    cout << endl << endl;
    
//wstawianie danych w pusta komórkę
    
    arkusz.setcontent(2, 3, "cos");

    arkusz.printout();

    cout << endl << endl;
    
//zamiana danych w komórce
    
    arkusz.setcontent(2, 3, 2137);

    arkusz.printout();

    cout << endl << endl;
    
// test sumowania liczb
    
    cout << arkusz.sumaliczbowa(1, 1, 2, 2);

    cout << endl << endl;

// test sumowania słów

    cout << arkusz.sumastring(1, 1, 2, 2);

    cout << endl << endl;
    
// test sumy sumy liczb i sumy słów naraz
    
    cout << arkusz.sumaintorazstring(1, 1, 2, 2);

    cout << endl << endl;
    
//test znajdowania najmnijszej liczby
    
    cout << arkusz.minimum(1, 1, 2, 2);

    cout << endl << endl;
    
//test znajdowania największej liczby
    
    cout << arkusz.maximum(1, 1, 2, 2);

    cout << endl << endl;
    
//test liczenia średniej liczb
    
    cout << arkusz.average(1, 1, 2, 2);

    cout << endl << endl;
    
//test zapisu arkusza do pliku
    
    arkusz.zapisdopliku("dane1.txt");

    cout << endl << endl;
    
//sprawdzanie czy zapis sie udał
    
    arkusz.odczytzpliku("dane1.txt");

    arkusz.printout();

    cout << endl << endl;
    
//test dodawania kolumny
    
    arkusz.addColumn();

    arkusz.printout();

    cout << endl << endl;
    
//test dodawania wirsza
    
    arkusz.addRow();

    arkusz.printout();

    cout << endl << endl;
    
//test dodawania wartości do komórki w nowym wierszu
    
    arkusz.setcontent(4, 2, 2137);

    arkusz.printout();

    cout << endl << endl;
    
//test usuwania kolumny
    
    arkusz.deleteColumn(4);

    arkusz.printout();

    cout << endl << endl;
    
//test usuwania wiersza
    
    arkusz.deleteRow(3);

    arkusz.printout();

    cout << endl << endl;
    
// test pobierania słowa jako liczbe
    
    cout << arkusz.getInt(0, 3);

    cout << endl << endl;
    
//test pobierania słowa jako słowo
    
    cout << arkusz.getString(0, 3);

    cout << endl << endl;
    
//test pobierania liczby jako liczbe
    
    cout << arkusz.getInt(0, 2);

    cout << endl << endl;
    
//test pobierania liczby jako słwo
    
    cout << arkusz.getString(0, 2);
    
//czyszcenie pamięci
    
    arkusz.~Spreadsheet();

    return 0;
}
