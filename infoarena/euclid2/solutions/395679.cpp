#include<iostream.h>
#include <fstream.h>
int main()
{
    int a,b,minim;
    ifstream fisin("euclid.in");
    fisin>>a;fisin>>b;
    fisin.close();
    ofstream fisout("euclid.out");
    if(a>b)
           minim=b;
    else
        minim=a;
    for (int i = minim; i>=1; i--)
            if (a % i == 0 && b % i == 0)
            {
                fisout<<i;
                break;
            }
  
   
   fisout.close();
}
