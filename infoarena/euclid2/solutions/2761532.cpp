#include <bits/stdc++.h>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<iomanip>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

long long euclid(long long a,long long b)
{
    if(b==0)
        return a;
    return euclid(b,a%b);
}

int main()
{
    long T;
    fin>>T;
    long long a,b;
    while(T--)
    {
        fin>>a>>b;
        fout<<euclid(a,b)<<'\n';
    }
    fin.close();
    fout.close();
    return 0;
}