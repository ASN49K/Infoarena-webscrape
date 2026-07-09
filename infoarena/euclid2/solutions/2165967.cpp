#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");


int k,a,b;
int main()
{
    f>>k;
    while(k)
    {
        f>>a>>b;
        if(a==b) g<<a<<endl;
        else
        {
            while(a!=b)
        {
            if(a>b) a=a-b; else b=b-a;
        }
        g<<a<<endl;
        }
        k--;
    }


    return 0;
}
