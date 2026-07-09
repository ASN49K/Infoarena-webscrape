#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int lnko(int a,int b){
    int m;
    while(b>0){
        m=b;
        b=a%b;
        a=m;
    }
    return a;
}

int main()
{
   int n;
   fin>>n;
   int a,b;
   for(int i=1;i<=n;i++){
        fin>>a>>b;
        fout<<lnko(a,b)<<"\n";
   }
}
