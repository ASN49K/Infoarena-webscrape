#include <bits/stdc++.h>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n,i,x,y,r;
int main()
{
    f>>n;
    for(i=1;i<=n;i++){
        f>>x>>y;
        int a=x;
        int b=y;
        while(b){
            r=a%b;
            a=b;
            b=r;
        }
        g<<a<<'\n';
    }
    return 0;
}
