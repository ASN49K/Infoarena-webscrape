#include <bits/stdc++.h>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n, i, x, y, r, a, b;
int main()
{
    fin>>n;
    for(i=1; i<=n; i++){
        fin>>x>>y;
        if(x==0||y==0)fout<<max(y,x)<<endl;
        else{
        if(max(x,y)%min(x,y)==0)fout<<min(x,y)<<endl;
        else{
            a=min(x,y);
            b=max(x,y);
            r=b%a;
         while(r!=0){
            if(b%a!=0){b=a; a=r; r=b%a;}

         }
         fout<<a<<endl;
        }
    }}
    return 0;
}
