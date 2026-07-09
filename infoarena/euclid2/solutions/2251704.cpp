#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int a,b,t,T,i=0;
    f>>T;
    while (i<T)
    {
    f>>a>>b;
    while (a!=b)
    {
       if (a>b)
           a=a-b;
       else b=b-a;

    }
    g<<a<<endl;
    i++;
    }
}

