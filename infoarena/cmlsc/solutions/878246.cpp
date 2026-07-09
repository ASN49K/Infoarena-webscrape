#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, nr = 0;
int a[1025], b[1025];
int lastStep = 0;
int valori[1025];

void citire()
{
    fin>>n>>m;
    for(int i = 0; i < n; i++)
        fin>>a[i];
    for(int j = 0; j < m; j++)
        fin>>b[j];
}

int main()
{
    citire();
    if(m<=n)
    {
        for(int i=0;i<n;i++)
            for(int j=lastStep; j<m;j++)
            {
                if(a[i]==b[j])
                {
                    lastStep = j;
                    valori[nr++] = a[i];
                }
            }
    }
    else
    {
        for(int j=0;j<m;j++)
            for(int i=lastStep; i<m;i++)
            {
                if(a[i]==b[j])
                {
                    lastStep = j;
                    valori[nr++] = a[i];
                }
            }
    }
    fout<<nr<<'\n';
    for(int i = 0;i<nr;i++)
        fout<<valori[i]<<' ';
    return 0;
}
