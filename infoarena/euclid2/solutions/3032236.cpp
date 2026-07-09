#include <bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    int r=0,n,i;
    long long a,b;
    fin>>n;
    for(i=1; i<=n; ++i){
    fin>>a>>b;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
fout<<a<<"\n";
    }
    //fin.close();
    //fout.close();
    return 0;
}
