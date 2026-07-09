#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{   int t,a,b,x,i;
    f>>t;
    for(i=1;i<=t;i++){
        f>>a>>b;
        while(b!=0){
            x=a%b;
            a=b;
            b=x;
        }
        g<<a<<endl;
    }
    return 0;
}
