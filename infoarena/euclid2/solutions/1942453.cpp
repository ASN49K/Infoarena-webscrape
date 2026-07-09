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
        while(a!=b)
        {
            if (a>b)
                a=a-b;
            else
                b=b-a;
        }
        int cmmdc;
        cmmdc=b;
        myWriteFile <<" "<<cmmdc<<" ";
    }


    return 0;
}
