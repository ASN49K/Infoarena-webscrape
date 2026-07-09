#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
   int i,n,a,b,c;
   fin>>n;
   for(i=0;i<n;i++)
   {
       fin>>a>>b;
       while(b){
        c=a%b;
        a=b;
        b=c;
       }
     fout<<a<<'\n';
   }
    return 0;
}
