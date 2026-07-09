#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream myReadFile;
    myReadFile.open("euclid2.in");
    int inputt;
    myReadFile >> inputt;
    ofstream myWriteFile;
    myWriteFile.open("euclid2.out");
    int a, b;
    while (myReadFile >> a>> b)
    {
        int t;
        while (b!=0)
        {
            t=b;
            b=a%b;
            a=t;
        }
        int cmmdc;
        cmmdc=a;
        myWriteFile <<cmmdc<<'\n';
    }


    return 0;
}
