#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int euclid(int a, int b)
{
    int i;


    if(a<b) swap (a,b);
    for(i=b;i>=1;i--)
    {
        if(a%i==0&&b%i==0) return i;
    }






}

int k,a,b;
int main()
{
    f>>k;
    while(k!=0)
    {


    f>>a>>b;
    g<<euclid(a,b)<<endl;
        k--;
    }
    return 0;



    }
