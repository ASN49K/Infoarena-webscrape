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
    int i;
    for (i=1; i<=inputt; i++)
    {
        int a, b;
        myReadFile>>a;
        myReadFile>>b;
        while(a!=b)
        {
            if (a>b)
                a=a-b;
            else
                b=b-a;
        }
        int cmmdc;
        cmmdc=b;
        if (cmmdc==1)
            myWriteFile <<" "<<0<<" ";
        else
            myWriteFile <<" "<<cmmdc<<" ";
    }
    return 0;
}
