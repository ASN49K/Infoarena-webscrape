#include<iostream.h>
#include <fstream.h>
int main()
{
    int a,b,r;
    ifstream fisin("euclid.in");
    fisin>>a;fisin>>b;
    fisin.close();
    while (b!=0)
    {
       r=a%b;
       a=b;
       b= r;
    }
   ofstream fisout("euclid.out");
   fisout<<a;
   fisout.close();
}
