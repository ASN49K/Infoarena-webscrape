#include <iostream>
#include <fstream>

using namespace std;

int CMMDC(int a, int b)
{
    if (b == 0)
        return a;
    else
        return CMMDC(b,a%b);
}

int main()
{
    ifstream fisierCitire ("euclid2.in");
    ofstream fisierIesire ("euclid2.out");
    int contor;
    int a,b;
    fisierCitire >> contor;
    for (int i=0; i<contor; i++)
    {
        fisierCitire>>a;
        fisierCitire>>b;
        fisierIesire<<CMMDC(a,b)<<endl;
    }
    fisierIesire.close();
}
