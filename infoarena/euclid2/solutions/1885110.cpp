#include <iostream>
#include <fstream>
using namespace std;

int main()
{
   int a,b;
   ifstream cmin(euclid2.in);
   ofstream cmout(euclid2.out);
    cmin>>a>>b;
    a1=a;
    b1=b;

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
