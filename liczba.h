#ifndef UNTITLED1_LICZBA_H
#define UNTITLED1_LICZBA_H
#include "komorka.h"

using namespace std;

class liczba : public komorka{

    int content;

public:
    //metoda sprawdza czy komurka jest liczbowa

    bool isNumeric() override;

    //metoda wprowadza do komórki słowo

    void setcontent(const string& content) override;

    //metoda wprowadza do komórki liczbe

    void setcontent(int content) override;

    //metoda pobiera wartość z komórki jako string

    string getString() override;

    //metoda pobiera wartość z komórki jako integer

    int getInt() override;

    //konstruktor liczby

    liczba() : content(0) {};

    //destruktor liczby




};


#endif //UNTITLED1_LICZBA_H
