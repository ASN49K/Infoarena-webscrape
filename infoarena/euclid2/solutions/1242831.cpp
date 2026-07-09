#include <fstream>
#include <cstdio>
using namespace std;
long long t,i,a,b,c;
int main(){
    freopen("euclid2.in","r",stdin);
    ofstream g ("euclid2.out");
    scanf("%ld",&t);
    for(i=1;i<=t;i++){
        scanf("%ld%ld",&a,&b);
        c=a%b;
        while(c){
            a=b;
            b=c;
            c=a%b;}
            g<<b<<'\n';}
            return 0;}
