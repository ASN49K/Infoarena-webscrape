#include <fstream>
#include <iostream>
#include <bits/stdc++.h>
///https://infoarena.ro/problema/euclid2
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int cmmdc(int a,int b)
{
    if(!b)
        return a;
    return cmmdc(b,a%b);
}
int main()
{
    int a,b;
    int T;
    fin>>T;
    while(T>0)
    {
        T--;
        fin>>a>>b;
        fout<<cmmdc(a,b)<<'\n';}
}
