#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int i,T,a,b,R;
int x[100001],y[100001];
int main ()
{
    f>>T;
    for(i=1;i<=T;i++){
        f>>x[i]>>y[i];
    }
    for(i=1;i<=T;i++){
        a=x[i];
        b=y[i];
        while(b>0){
            R=a%b;
            a=b;
            b=R;
        }
        g<<a<<endl;
    }
    return 0;
}
