#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int cmmdc(int a,int b){
int r;
r=a%b;
while(r){
    a=b;
    b=r;
    r=a%b;
}
return b;
}
int main()
{
    int n,x,y;
    f>>n;
    while(n){
        f>>x>>y;
        g<<cmmdc(x,y)<<'\n';
        n--;
    }
    return 0;
}
