#include <fstream>
using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int main()
{
   int a,b,r,T;
   cin>>T;
   while(T != 0)
   {
       cin>>a>>b;
       r=a%b;
       while(r){
        a=b;
        b=r;
        r=a%b;
       }
       cout<<b<<'\n';
   }
    return 0;
}
