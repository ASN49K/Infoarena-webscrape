#include <iostream>
#include <fstream>

using namespace std;

ifstream fisierCitire ("euclid2.in");
ofstream fisierIesire ("euclid2.out");
int contor;
int a,b,r;

int CMMDC(int a, int b)
{
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    fisierIesire<<a<<endl;
}

int main()
{
    fisierCitire >> contor;
    for (int i=0; i<contor; i++)
    {
        fisierCitire>>a;
        fisierCitire>>b;
        CMMDC(a,b);
    }
    fisierIesire.close();
}
