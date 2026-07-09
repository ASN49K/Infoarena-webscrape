#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
unsigned long a,b,t;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int euclid(unsigned long x,unsigned long y)
{
    unsigned long z=x%y;
    if(!z)
        return y;
    else
        euclid (y,z);
}
void citire()
{
    fin>>t;
    while(t)
    {
        {
            fin>>a>>b;
            if(a<b)
                swap(a,b);
            cout<<euclid(a,b)<<endl;
        }
        --t;
    }
}
int main()
{
    citire();
    return 0;
}
