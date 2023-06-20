#include <iostream>
#include "Spreadsheet.h"

using namespace std;

int main(){

    //testy poprawnego działania programu

    Spreadsheet arkusz;

    arkusz.odczytzpliku("dane.txt");

    arkusz.printout();

    cout << endl << endl;

    arkusz.clearCell(2, 3);

    arkusz.printout();

    cout << endl << endl;

    arkusz.setcontent(2, 3, "cos");

    arkusz.printout();

    cout << endl << endl;

    arkusz.setcontent(2, 3, 2137);

    arkusz.printout();

    cout << endl << endl;

    cout << arkusz.sumaliczbowa(1, 1, 2, 2);

    cout << endl << endl;

    cout << arkusz.sumastring(1, 1, 2, 2);

    cout << endl << endl;

    cout << arkusz.sumaintorazstring(1, 1, 2, 2);

    cout << endl << endl;

    cout << arkusz.minimum(1, 1, 2, 2);

    cout << endl << endl;

    cout << arkusz.maximum(1, 1, 2, 2);

    cout << endl << endl;

    cout << arkusz.average(1, 1, 2, 2);

    cout << endl << endl;

    arkusz.zapisdopliku("dane1.txt");

    cout << endl << endl;

    arkusz.odczytzpliku("dane1.txt");

    arkusz.printout();

    cout << endl << endl;

    arkusz.addColumn();

    arkusz.printout();

    cout << endl << endl;

    arkusz.addRow();

    arkusz.printout();

    cout << endl << endl;

    arkusz.setcontent(4, 2, 2137);

    arkusz.printout();

    cout << endl << endl;

    arkusz.deleteColumn(4);

    arkusz.printout();

    cout << endl << endl;

    arkusz.deleteRow(3);

    arkusz.printout();

    cout << endl << endl;

    cout << arkusz.getInt(0, 3);

    cout << endl << endl;

    cout << arkusz.getString(0, 3);

    cout << endl << endl;

    cout << arkusz.getInt(0, 2);

    cout << endl << endl;

    cout << arkusz.getString(0, 2);

    arkusz.~Spreadsheet();

    return 0;
}
