#include <bits/stdc++.h>

using namespace std;
int T,a,i,b,r,t;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
 f>>T;
 for(i=1;i<=T;i++){
    f>>a>>b;
    while(b){
        r=a%b;
        a=b;
        b=r;

    }
  g<<a<<endl;

 }
    return 0;
}