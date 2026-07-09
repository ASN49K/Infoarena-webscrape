/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int a,b,r,t,i,c[10002];
int main()
{
    fin>>t;
    for(i=1;i<=t;i++)
    {
        fin>>a>>b;
        while(a)
        {
            r=b%a;
            b=a;
            a=r;
        }
        c[i]=b;
    }
    for(i=1;i<=t;i++)
    {
        fout<<c[i]<<'\n';
    }
    return 0;
}
