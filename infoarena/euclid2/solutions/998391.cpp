#include <iostream>
#include <fstream>

using namespace std;

int CMMDC(int a, int b)
{
    while(b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main()
{
    ifstream fisierCitire ("euclid2.in");
    ofstream fisierIesire ("euclid2.out");
    int contor;
    int a,b;
    fisierCitire >> contor;
    for (int i=0; i<contor; i++)
        fisierCitire>>a;
        fisierCitire>>b;
        fisierIesire<<CMMDC(a,b)<<endl;
    }
    fisierIesire.close();
}
