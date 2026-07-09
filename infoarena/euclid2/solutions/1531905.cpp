#include <bits/stdc++.h>

using namespace std;

inline int euclid(int a, int b)
{
    if(!b) return a;
    return euclid(b,a%b);
}

int main()
{
    int n,x,y,i;
    ofstream fout("euclid2.out");
    ifstream fin("euclid2.in");
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>x>>y;
        fout<<euclid(x,y)<<"\n";
    }
    fin.close();
    fout.close();
    return 0;
}
