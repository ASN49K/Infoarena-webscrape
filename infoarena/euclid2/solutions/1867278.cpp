#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
  ifstream in("euclid2.in");
  ofstream g("euclid2.out");
 int main(){
 int a,b,n,i;
  in>>n;
    for(i=0;i<n;i++)
     {
          in>>a>>b;
           if(b==1)
            g<<a<<"\n";
           if(a==1)
           g<<b<<"\n";
           else
           {while(a!=b)
             {
                  if(a>b)
                  a=a-b;
                  else
                b=b-a;
             }
             g<<a<<"\n";
           }

     }

}
