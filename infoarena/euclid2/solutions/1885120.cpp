#include <iostream>
#include <fstream>
using namespace std;

int main()
{
   int a,b,i,t;
   ifstream cmin("euclid2.in");
   ofstream cmout("euclid2.out");
   cmin>>t;
   for(i=1;i<=t;++i){
    cmin>>a>>b;

    while(a!=0 && b!=0){
        if (a>=b){

            a=a-b;

        }
        else{

            b=b-a;

        }

    }
    if(a==0){
        cmout<<b<<endl;
    }
    else{
        cmout<<a<<endl;
    }
   }

}
