#include <iostream>
#include <fstream>
using namespace std;

int euclid(int a, int b)
{
    if(b==0 || a==0) return b==0 ? a : b;
    else return a > b ? euclid(b, a%b) : euclid(a, b%a);
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