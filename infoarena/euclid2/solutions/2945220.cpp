#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

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