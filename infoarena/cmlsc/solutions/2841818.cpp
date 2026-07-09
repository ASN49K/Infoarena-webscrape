#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{
    int n, m, a[1025], b[1025], c[1025], d[1025], S = 0, var = 0, G = 0;
    fin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        fin >> a[i];
    }
    for(int i = 0; i < m; i++)
    {
        fin >> b[i];
    }
    if(n < m)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(a[i] == b[j])
                {
                    c[S] = a[i];
                    S++;
                }
            }
        }
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < S; j++)
            {
                if(c[j] == b[i])
                {
                    d[G] = c[j];
                    G++; 
                }
            }
        }
    }
    else
    {
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(b[i] == a[j])
                {
                    c[S] = b[i];
                    S++;
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < S; j++)
            {
                if(c[j] == a[i])
                {
                    d[G] = c[j];
                    G++; 
                }
            }
        }
    }
    for(int i = 0; i < S; i++)
    {
        if(c[i] != d[i])
        {
            for (int j = i; j < S - var; ++j)
            {
                d[j] = d[j + 1];
            }
            var++;
        }
    }
    fout << S - var << endl;
    for(int i = 0; i < S - var; i++)
    {
        fout << d[i] << " ";
    }
}