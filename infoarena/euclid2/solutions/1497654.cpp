#include <iostream>
#include <fstream>
using namespace std;

class XYZ{

private:
    int x;
    int y;
    int z;
    long number;

public:
    XYZ(int x, int y, int z);
    int getNewNumber(){
        number = 0;
        number += y;
        for(int i=0; i<x-1; ++i){
            number = number*10+z;
        }

        return number;
    }

};

XYZ::XYZ(int newX, int newY, int newZ){
    x = newX;
    y = newY;
    z = newZ;
}

int main()
{
    ifstream input("xyz.in");
    ofstream output("xyz.out");
    int x, y, z;
    input>>x>>y>>z;

    XYZ numar(x,y,z);

    output<<numar.getNewNumber();
}
