#include <iostream>
#include <fstream>
using namespace std;
ifstream  fin("euclid.in");
ofstream fout("euclid.out");
int t,i,a,b,d;
int main()
{
    fin>>t;
    for(i=1;i<=t;i++)
    {
        while(b!=0)
        {
            t=b;
            b=a%b;
            a=d;
        }
    }
    fout<<d;
    fin.close();
    fout.close();
    return 0;
}
