#include <bits/stdc++.h>
using namespace std;

string problem = "euclid2";
ifstream fin (problem + ".in");
ofstream fout(problem + ".out");

//https://www.infoarena.ro/problema/euclid2

int euclid(int a,int b)
{
    while(b)
    {
        int aux = a % b;
        a = b;
        b = aux;
    }
    return a;
}

int main()
{
    int t;
    fin >> t;
    while(t--)
    {
        int a,b;
        fin >> a >> b;
        fout << euclid(a,b) << "\n";
    }
}
