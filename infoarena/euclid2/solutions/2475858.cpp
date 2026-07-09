#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a,int b)
{
    int r = a % b;
    while(r)
    {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}
int main()
{
    int n ;
    fin >> n ;
    int a , b ;
    while (n--)
    {
        fin >> a >> b;
        fout << cmmdc(a,b) << endl ;
    }
    fin.close();
    fout.close();
    return 0;
}
