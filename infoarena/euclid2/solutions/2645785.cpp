
#include <iostream>
#include <fstream>
using namespace std;
ifstream be("euclid2.in");
ofstream ki("euclid2.out");
long lnkoRek(long a,long b)
{
    if(a==0)return b;
    else if(b==0)return a;
    else if(a>b)return lnkoRek(a%b,b);
    else return lnkoRek(a,b%a);


}

int main()
{

     long n,a,b;
     be>>n;
     for(int i=1;i<=n;++i)
     {
         be>>a>>b;
         ki<<lnkoRek(a,b)<<endl;

     }


    return 0;

}
