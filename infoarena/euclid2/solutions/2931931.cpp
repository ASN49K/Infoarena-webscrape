#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int t,a,b,i;
int main()
{
    fin>>t;
    for(i=1;i<=t;i++){
        fin>>a>>b;///8 6
        while(b!=0){
            int r=a%b;///r =2 r=0
            a=b;///a=6 a=2
            b=r;///b=2 b=0
        }
        cout<<a<<"\n";
        }
    return 0;
}
