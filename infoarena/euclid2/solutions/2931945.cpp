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
        fin>>a>>b;
        while(b!=0){
            int r=a%b;
            a=b;
            b=r;
        }
        fout<<a<<"\n";
        }
    return 0;
}
