//#include <iostream>
#include <fstream>

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

using namespace std;

int main()
{
          int a, b, t, r;

          cin>>t;

          for(int i=1; i<=t; i++){
          cin>>a>>b;
        while(b!=0)
             {r=a%b;
              a=b;
              b=r;}
       cout<<a<<"\n";}




    return 0;
}
