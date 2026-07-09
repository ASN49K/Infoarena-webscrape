#include<fstream.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,n;
    int cmmdc(int a, int b)
{
    if (!b) return a;
    return cmmdc(b, a % b);
}
int main(){
    f>>n;
    for(int i=1; i<=n;i++){
    f>>a>>b;
    g<<cmmdc(a,b)<<"\n";
}
}
