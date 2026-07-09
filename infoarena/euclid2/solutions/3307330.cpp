#include <bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int r;
int cdc(int a, int b){
   
    if(a%b==0){
        return b;
    }else{
        return gcd(b,a%b);
    }
    
    
}
int main()
{
   int a,b,c,cmmdc;
   int n;
   fin>>n;
   for(int i=1; i<=n; i++){
         fin>>a>>b;
         fout<<cdc(a,b)<<"\n";
   }

    return 0;
}