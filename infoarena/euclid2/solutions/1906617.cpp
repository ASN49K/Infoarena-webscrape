#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int i,T,a,b,R;
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
        g<<a<<endl;
    }
    return 0;
}
