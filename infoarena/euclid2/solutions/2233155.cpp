#include <iostream>
#include <fstream>
using namespace std;

int euclid(int a, int b)
{
    if(!b) return a;
    else return  euclid(b, a%b);
}

int main()
{
    int perechi=0;
    ifstream fileIN;
    ofstream fileOut;
    fileIN.open("euclid2.in");
    fileOut.open("euclid2.out");
    fileIN >> perechi;

    for(int i=0; i<perechi;i++)
    {
        int a,b;
        fileIN >> a >> b;
        fileOut << euclid(a,b) << endl;        
    }
    fileIN.close();
    fileOut.close();
    return 0;

}