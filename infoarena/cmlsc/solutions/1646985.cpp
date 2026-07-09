#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int main ()
{
    int n,m;
    fin>>n>>m;
    int a[n];
    int b[m];
    for (int i=0;i<n;i++)
    {
        fin>>a[i];
    }
    for (int i=0;i<m;i++)
    {
        fin>>b[i];
    }
    int caut=0;
    int poz=0;
    while (poz<m)
    {
        for (int i=caut;i<n;i++)
        {
            if(a[i]==b[poz])
            {
                caut=i;
                poz++;
                fout<<a[i]<<" ";
            }
        }
        poz++;
    }
}
