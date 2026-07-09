#include <bits/stdc++.h>

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

using namespace std;

int main()
{
    int a,b;
    fin>>a>>b;
    while(b)
    {
        int r=a%b;
        a=b;
        b=r;
    }
    fout<<a;
    return 0;
}