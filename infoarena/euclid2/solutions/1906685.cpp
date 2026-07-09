#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int i,T,a,b,R,K;
int x[100001];
int main ()
{
    f>>T;
    for(i=1;i<=T;i++){
        f>>a>>b;
        while(b>0){
            R=a%b;
            a=b;
            b=R;
        }
        K++;
        x[K]=a;
    }
    for(i=1;i<=K;i++){
        g<<x[i]<<endl;
    }
    return 0;
}
