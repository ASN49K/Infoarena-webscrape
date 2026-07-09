#include<iostream.h>
#include <fstream.h>
int eucl(int a, int b)
{
    if(a==b) return a;
    if(a>b)
           return eucl(a-b,b);
    else
        return eucl(a,b-a);
}
int main()
{
    int a,b,minim;
    ifstream fisin("euclid.in");
    fisin>>a;fisin>>b;
    fisin.close();
    ofstream fisout("euclid.out");
    fisout<<eucl(a,b);
  
   
   fisout.close();
}
