#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

long long int euclid(long long int a,long long int b){
    while(a!=0 && b!=0){
        if(a>b)
            a=a%b;
        else
            b=b%a;
    }
    if(a==0)
        return b;
    else
        return a;

}

int main()
{
   ifstream f("euclid2.in",ios::in);
   ofstream g("euclid2.out",ios::out);
   long long int t;
   f>>t;

   while(t){
        long long int a,b;
        f>>a>>b;
        g<<euclid(a,b)<<endl;
        t--;
   }




}
