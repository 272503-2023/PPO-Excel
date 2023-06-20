#include <iostream>
#include "liczba.h"


using namespace std;

bool liczba :: isNumeric(){

    return true;

}

void liczba :: setcontent( int content1){

    this -> content = content1;

}
void liczba :: setcontent(const string& content1){

}

int liczba :: getInt(){

    return content;

}
string liczba ::getString() {

    return to_string(content);

}



