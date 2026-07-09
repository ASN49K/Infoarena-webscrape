#include <bits/stdc++.h>
#define N 100001

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int n;

void Citire()
{
    fin >> n;
}

void Rezolvare()
{
    int x, s = 0;
    while( n-- )
    {
        fin >> x;
        s = s ^ x;
    }
    if( s == 0 ) fout << "NU\n";
    else fout << "DA\n";
}

int main()
{
    int task;
    fin >> task;
    while(task--)
    {
        Citire();
        Rezolvare();
    }
    return 0;
}
