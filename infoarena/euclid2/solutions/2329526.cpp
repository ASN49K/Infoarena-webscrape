#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int T;
    fin>>T;
    int a , b ,r;
    int cmmdc,i;
    for(i=1;i<=T;i++)
    {
        fin>>a>>b;
         fout<<__gcd(a,b)<<endl;
    }
    fin.close();
    fout.close();
    return 0;
}
