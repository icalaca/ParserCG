#include "Parser.hpp"
#include <iostream>

using namespace std;
int main(void){
    Parser p = Parser("teste");
    cout << "Number of Colors:" << p.getNumColors() << endl;
    cout << "Colors:" << endl;
    for(int i = 1; i < p.getNumColors() + 1; i++){
        int r = p.getColorR(i);
        int g = p.getColorG(i);
        int b = p.getColorB(i);
        cout << "R:" << r << " G:" << g << " B:" << b << endl;
    }
    cout << "Number of Objects:" << p.getNumObjs() << endl;
    cout << "Objects:" << endl;
    cout << "------------------------" << endl;
    for(int i = 0; i < p.getNumObjs(); i++){
        cout << "Obj ID:" << i << endl;
        cout << "Obj Lines:" << p.getObjNumLines(i) << endl;
        cout << "Obj Columns:" << p.getObjNumColumns(i) << endl;
        for(int j = 0; j < p.getObjNumLines(i); j++){
            for(int k = 0; k < p.getObjNumColumns(i); k++){
                cout << p.getObjElement(i, j, k) << " ";
            }
            cout << endl;
        }
        cout << "------------------------" << endl;
    }
    return 0;
}