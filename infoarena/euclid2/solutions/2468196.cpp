#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a,int b)
{
    int r;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
    vector <int> result;
    int n;
    fin>>n;
    int a,b;
    int i;
    for(i=1; i<=n; i++)
    {
        fin>>a>>b;
        result.push_back(cmmdc(a,b));
    }
    for(size_t k=0; k<result.size(); k++)
        fout<<result[k]<<"\n";
    return 0;
}
