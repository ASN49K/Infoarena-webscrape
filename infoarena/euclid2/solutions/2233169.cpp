#include <iostream>
#include <fstream>
using namespace std;


//recursive
int euclid(int a, int b)
{
    if(!b) return a;
    else return  euclid(b, a%b);
}

//iterative
int gcd(int a, int b)
{
    int r;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
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
        fileOut << gcd(a,b) << "\n";        
    }
    fileIN.close();
    fileOut.close();
    return 0;

}