#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a,int b)
{
    int r;
    while(r!=0)
    {
        r=a%b;
        a=b;
        a=r;
    }
    return a;
}
int main()
{
    int n ;
    fin >> n ;
    int a , b ;
    while (fin >> a >> b)
        cout << cmmdc(a,b) << "\n" ;
    fin.close();
    fout.close();
    return 0;
}
