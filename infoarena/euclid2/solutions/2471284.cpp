#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

void cmmdc(int x,int y)
{
    int r;
    while(r!=0)
    {
        r=x%y;
        x=y;
        y=r;
    }
    fout << x << "\n" ;
}
int main()
{
    int T ;
    fin >> T ;
    int a , b ;
    while (fin >> a >> b)
    {
        cmmdc(a,b);
    }
    fin.close();
    fout.close();
    return 0;
}
