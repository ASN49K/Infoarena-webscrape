#include <iostream>
#include <fstream>
using namespace std;

int cmmdc(unsigned int nr1, unsigned int nr2){
    while (nr1!=nr2){
        if (nr2>nr1)
            nr2-=nr1;
        else
            nr1-=nr2;
    }
    return nr1;
}

int main()
{
    unsigned int nr1,nr2,nrPerechi;
    ifstream iFile("euclid.in");
    ofstream oFile("euclid.out");
    iFile>>nrPerechi;
    while (nrPerechi){
        iFile>>nr1>>nr2;
        nrPerechi--;
        oFile<<cmmdc(nr1,nr2)<<endl;
    }
    iFile.close();
    oFile.close();
    return 0;
}
