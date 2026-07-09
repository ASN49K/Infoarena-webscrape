#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int gcd(int a,int b){
    if(b)
        return a;
    return(b, a%b);
}

int main()
{
   int i,n,a,b;
   fin>>n;
   for(i=0;i<n;i++)
   {
       fin>>a>>b;
       fout<<gcd(a,b)<<endl;
   }
    return 0;
}
