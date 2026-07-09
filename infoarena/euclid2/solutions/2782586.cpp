#include <bits/stdc++.h>

using namespace std;

fstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc(int a, int b)
{
    if(b == 0)
        return a;
    else
        return cmmdc(b, a%b);
}

int main()
{
    long long int t, j=1;
    long long int a, b, vect[100001];
    f>>t;
    for(int i=1; i<=t; i++)
    {
        f>>a>>b;
        vect[j] = cmmdc(a, b);
        j++;
    }

    for(int k=1; k<j; k++)
        g<<vect[k]<<endl;

    return 0;
}
