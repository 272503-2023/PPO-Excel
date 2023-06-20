#ifndef UNTITLED1_KOMORKA_H
#define UNTITLED1_KOMORKA_H


using namespace std;

class komorka {


public:

    virtual ~komorka() {};
    virtual bool isNumeric() = 0;
    virtual string getString() = 0;
    virtual int getInt() = 0;
    virtual void setcontent(const string& content) = 0;
    virtual void setcontent(int content) = 0;

};



#endif //UNTITLED1_KOMORKA_H
