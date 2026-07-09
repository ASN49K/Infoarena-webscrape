#include <iostream>
#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmmc(int a,int b){
    if(b==0)return a;
    cmmmc(b,a%b);
}

int main()
{
   int n,a,b;

   f>>n;
   while(n){
    f>>a>>b;
    g<<cmmmc(a,b)<<"\n";
    n--;
   }
}
