#include <iostream>
#include <fstream>
using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int euclid(long int a,long int b)
{
    int c;
    if (a<b)
    {
        c=a;
        a=b;
        b=c;
    }
    while (b!=0) {
        c = b;
        b = a % b;
        a = c;
    }
    return a;
}

int main ()
{
    int t;//T reprezinta numarul de perechi de numere
    long int a,b;
    fin >>t;
    for (int i = 1;i <= t;i++)
    {
        fin >>a >>b;
        fout << euclid(a,b)<<endl;
    }
    return 0;
}
