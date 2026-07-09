#include<bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int GCD(int A, int B)
{
    if(!B)
        return A;
    return GCD(B, A%B);
}
int main ()
{
    int n,x,y;
    fin>>n;
    for (int i=0;i<n;i++)
    {
        fin>>x>>y;
        fout<<GCD(x,y)<<endl;
    }
}

