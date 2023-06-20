#ifndef UNTITLED1_SLOWO_H
#define UNTITLED1_SLOWO_H
#include <string>
#include "komorka.h"

using namespace std;

class slowo : public komorka{

    string content;

public:
    //metoda sprawdza czy komurka jest liczbowa

        bool isNumeric() override;

    //konstruktor slowa

        slowo(): content("") {};

    //metoda wprowadza do komórki słowo

        void setcontent(const string& content) override;

    //metoda wprowadza do komórki liczbe

        void setcontent(int content) override;

    //metoda pobiera wartość z komórki jako string

        string getString() override;

    //metoda pobiera wartość z komórki jako integer

        int getInt() override;



};

#endif //UNTITLED1_SLOWO_H
