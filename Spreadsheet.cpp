#include "Spreadsheet.h"



void Spreadsheet::addRow() {
    cells.resize(cells.size() + 1);
    cells[cells.size()-1].resize(cells[0].size());
    for(auto & i : cells[cells.size()-1]){
        i = nullptr;
    }
}

void Spreadsheet::addColumn() {
    for (auto & cell : cells)
    {
        cell.resize(cell.size() + 1, nullptr);
    }

}

void Spreadsheet::deleteRow(int row)
{
    if (row < cells.size())
    {
        cells.erase(cells.begin() + row);
    }
}

void Spreadsheet::deleteColumn(int column)
{
    if (column < cells[0].size())
    {
        for (auto &cell: cells)
            cell.erase(cell.begin() + column);

    }
}

void Spreadsheet::clearCell(int row, int column) {
    if (row >= cells.size())
    {
        cells.resize(row + 1);
    }
    if (column >= cells[row].size())
    {
        cells[row].resize(column + 1);
    }
    cells[row][column] = nullptr;

}
bool Spreadsheet::isstring(const string& content)
{
    for (char i : content)
    {
        if (isdigit(i) != 0)
            continue;
        return true;
    }
    return false;
}



void Spreadsheet::setcontent(int row, int column,const int& content) {

    if (row >= cells.size())
        cells.resize(row + 1);

    if (column >= cells[row].size())
        cells[row].resize(column + 1, nullptr);

    if (cells[row][column] == nullptr || !cells[row][column]->isNumeric())
        cells[row][column] = new liczba();

    cells[row][column]->setcontent(content);
}

void Spreadsheet :: setcontent(int row, int column,const string& content) {

    if (row >= cells.size())
        cells.resize(row + 1);

    if (column >= cells[row].size())
        cells[row].resize(column + 1,nullptr);

    if (cells[row][column] == nullptr || cells[row][column]->isNumeric()) {
        if (isstring(content))
            cells[row][column] = new slowo();
        else
            cells[row][column] = new liczba();
    }

    cells[row][column]->setcontent(content);

}

bool Spreadsheet :: isCellValid(int row, int column){

    if (row < cells.size() && column < cells[row].size() && cells[row][column] != nullptr)
        return true;
    else
        return false;

}

int Spreadsheet::getInt(int row, int column)
{
    if (isCellValid(row, column))
        return cells[row][column]->getInt();
    else
        return 0;

}

string Spreadsheet::getString(int row, int column) {
    if (isCellValid(row, column))
        return cells[row][column]->getString();
    else
        return 0;
}


void Spreadsheet::printout() {

    for (auto &row : cells)
    {
        for (auto &komorka : row)
        {
            if(komorka == nullptr){
                cout << "   | ";
                continue;}
            cout << komorka->getString() << " | ";
        }
        cout << endl;
    }
}

int Spreadsheet::sumaliczbowa(int row1, int col1, int row2, int col2){
    int sum =0;

    for (int i = row1; i <= row2; i++) {
        for (int j = col1; j <= col2; j++) {
            if (isCellValid(i, j)) {
                komorka *cell = cells[i][j];
                if (cell->isNumeric()) {
                    sum += cell->getInt();
                }
            }
        }
    }

    return sum;
}

string Spreadsheet::sumastring(int row1, int col1, int row2, int col2){
    string sum = "";

    for (int i = row1; i <= row2; i++) {
        for (int j = col1; j <= col2; j++) {
            if (isCellValid(i, j)) {
                komorka *cell = cells[i][j];
                if (!cell->isNumeric()) {
                    sum += cell->getString();
                }
            }
        }
    }

    return sum;
}

string Spreadsheet::sumaintorazstring(int row1, int col1, int row2, int col2){
    string sumastring = "";
    int suma = 0;

    for (int i = row1; i <= row2; i++) {
        for (int j = col1; j <= col2; j++) {
            if (isCellValid(i, j)) {
                komorka *cell = cells[i][j];
                if (!cell->isNumeric()) {
                    sumastring += cell->getString();
                }
                else if (cell->isNumeric()) {
                    suma += cell->getInt();
                }
            }
        }
    }

    return sumastring + to_string(suma);
}

int Spreadsheet::minimum(int row1, int col1, int row2, int col2){
    int minimum = INT_MAX;

    for (int i = row1; i <= row2; i++) {
        for (int j = col1; j <= col2; j++) {
            if (isCellValid(i, j)) {
                komorka *cell = cells[i][j];
                if (cell->isNumeric()) {
                    if (cells[i][j]->getInt() < minimum)
                    {
                        minimum = cells[i][j]->getInt();
                    }
                }
            }
        }
    }
    if (minimum == INT_MAX){
        cout << "nie ma liczb";
    }
    else return minimum;
return 0;
}

int Spreadsheet::maximum(int row1, int col1, int row2, int col2){
    int maximum = INT_MIN;

    for (int i = row1; i <= row2; i++) {
        for (int j = col1; j <= col2; j++) {
            if (isCellValid(i, j)) {
                komorka *cell = cells[i][j];
                if (cell->isNumeric()) {
                    if (cells[i][j]->getInt() > maximum)
                    {
                        maximum = cells[i][j]->getInt();
                    }
                }
            }
        }
    }
    if (maximum == INT_MIN){
        cout << "nienapotkano liczb";
    }
    else return maximum;
   return 0;
}

int Spreadsheet::average(int row1, int col1, int row2, int col2){
    int sum =0;
    int count = 0;
    for (int i = row1; i <= row2; i++) {
        for (int j = col1; j <= col2; j++) {
            if (isCellValid(i, j)) {
                komorka *cell = cells[i][j];
                if (cell->isNumeric()) {
                    sum += cell->getInt();
                    count ++;
                }
            }
        }
    }
    if(count != 0)
        return sum/count;
    else cout << "nienapotkano liczb";
    return 0;
}

void Spreadsheet::zapisdopliku(string plik1) {
    ofstream plik;
    plik.open(plik1);
    if (plik.is_open())
    {

        plik << cells.size()<< " " << cells[0].size() << endl;
        for (auto & cell : cells)
        {
            for (auto & j : cell)
            {
                if (j != nullptr)
                {
                    plik <<j->getString() << " ";
                }
            }
        plik << endl;
        }
    }
    plik.close();
}

void Spreadsheet::odczytzpliku(string plik1) {
    ifstream plik;
    plik.open(plik1);

    int rows, columns;
    string content;
    if (plik.is_open()) {
        plik >> rows >> columns;

        cells.resize(rows);
        for (int i = 0; i < rows; i++) {

            cells[i].resize(columns);
            for (int j = 0; j < columns; j++) {

                plik >> content;

                int litery = 0;
                for (int k = 0; k < content.length(); k++) {
                    if (!isdigit(content[k])) {
                        litery++;
                    }
                }

                if (litery != 0) {

                    cells[i][j] = new slowo();
                } else {

                    cells[i][j] = new liczba();

                    cells[i][j]->setcontent(stoi(content));
                }

                cells[i][j]->setcontent(content);
            }
        }
    }

    plik.close();
}



Spreadsheet :: ~Spreadsheet() {

    for (auto &row : cells)
    {
        for (auto &komorka : row)
        {
            delete komorka;
        }
    }


}



