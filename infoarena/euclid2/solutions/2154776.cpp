#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int T,x,y;

int euclid(int x, int y)
{
    int aux;
    while(y!=0)
    {
        aux = y;
        y = x % y;
        x = aux;
    }
    return x;
}

int euclid_recursiv(int x , int y)
{
    if(y == 0)
        return x;
    else
        return euclid_recursiv(y, x % y);
}

int main()
{
    fin >> T;
    for(int i = 1; i<= T; ++i)
    {
        fin >> x >> y;
        fout<<euclid_recursiv(x,y) << endl;
    }
    return 0;
}
