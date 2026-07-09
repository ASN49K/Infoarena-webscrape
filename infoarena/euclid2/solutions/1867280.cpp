#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
  ifstream in("euclid2.in");
  ofstream g("euclid2.out");
 int main(){
 int a,b,r,n,i;
  in>>n;
    for(i=0;i<n;i++)
     {
          in>>a>>b;
          r=a%b;
            while(r)
             {
               a=b;
               b=r;
               r=a%b;
             }
             g<<b<<"\n";


     }

}
