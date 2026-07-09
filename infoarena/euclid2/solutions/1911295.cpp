#include <iostream>
#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t,a,b,R,i;
int main()
{
    f>>t;
    for(i=1;i<=t;i++){
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
