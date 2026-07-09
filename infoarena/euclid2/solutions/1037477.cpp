#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int a,b,r,n,i;
    fin>>n;
    for(i=1;i<=n;i++){
        fin>>a>>b;
        if(b==0)
            fout<<0<<"\n";
        else{
            r=a%b;
            while(r){
                a=b;
                b=r;
                r=a%b;
            }
            fout<<b<<"\n";
        }
    }
    return 0;
}
