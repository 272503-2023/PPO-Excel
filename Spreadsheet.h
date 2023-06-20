#ifndef UNTITLED1_SPREADSHEET_H
#define UNTITLED1_SPREADSHEET_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "komorka.h"
#include "liczba.h"
#include "slowo.h"


using namespace std;

class Spreadsheet {
protected:
    std::vector<std::vector<komorka*>> cells;

public:
    //metoda dodaje wiersz

        void addRow();

    //metoda dodaje kolumne

        void addColumn();

    //metoda usuwa wiersz

        void deleteRow(int row);

    //metoda usuwa kolumne

        void deleteColumn(int col);

    //metoda czyści komórke

        void clearCell(int row, int column);

    //metoda sprawdza czy zawartośc komórki to słowo

        static bool isstring(const string& content);

    //metoda wprowadza do komórki liczbe

        void setcontent(int row, int column,const int& content);

    //metoda wprowadza do komórki słowo

        void setcontent(int row, int column,const string& content);

    //metoda sprawdza czy wskazana komórka należy do arkusza i czy nie jest to nullptr

        bool isCellValid(int row, int column);

    //metoda pobiera wartość z komórki jako integer

        int getInt(int row, int col);

    //metoda pobiera wartość z komórki jako string

        string getString(int row, int col);

    //metoda wyświetla zawartość arkusza

        void printout();

    //metoda sumuje liczby z zakresu

        int sumaliczbowa(int row1, int col1, int row2, int col2);

    //metoda sumuje słowa z zakresu

        string sumastring(int row1, int col1, int row2, int col2);

    //metoda sumuje liczby i liczby z zakresu

        string sumaintorazstring(int row1, int col1, int row2, int col2);

    //metoda znajduje najmniejszą liczbe z zakresu

        int minimum(int row1, int col1, int row2, int col2);

    //metoda znajduje największą liczbe z zakresu

        int maximum(int row1, int col1, int row2, int col2);

    //metoda znajduje średnią liczb z zakresu

        int average(int row1, int col1, int row2, int col2);

    //metoda zapisuje arkusz z wskazanego pliku

        void zapisdopliku(string plik1);

    //metoda pobiera arkusz z wskazanego pliku

        void odczytzpliku(string plik1);

    //metoda usuwa arkusz

        ~Spreadsheet();



};



#endif //UNTITLED1_SPREADSHEET_H
