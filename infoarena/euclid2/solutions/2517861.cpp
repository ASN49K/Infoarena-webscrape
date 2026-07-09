#include <bits/stdc++.h>
#define open ios::sync_with_stdio(false);
#define close fin.close(); fout.close(); return 0;
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int a, b;
int euclid()
{
    int aux;
    while(b)
    {
        aux = a % b;
        a = b;
        b = aux;
    }
    return a;
}
void citire()
{
    fin >> a >> b;
}
int main()
{
    open
    int t;
    fin >> t;
    while(t--)
    {
        citire();
        fout << euclid() << "\n";
    }
    close
}
