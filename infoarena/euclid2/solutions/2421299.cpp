#include <iostream>
#include <fstream>
using namespace std;
ifstream f("ciur.in");
ofstream g("ciur.out");
int main()
{
    long long int N;
    int i, nr=1;
    f>>N;
    for(i=1;i<=N;i++)
    {
        if(i!=2 && i!=3 && i!=5 && i!=7 && i!=11 && i!=13 && i!=17 && i!=19)
        {
            if(i%2==0)
                nr++;
            else if(i%3==0)
                nr++;
            else if(i%5==0)
                nr++;
            else if(i%7==0)
                nr++;
            else if(i%11==0)
                nr++;
            else if(i%13==0)
                nr++;
            else if(i%17==0)
                nr++;
            else if(i%19==0)
                nr++;
        }
    }
    if(N>nr)
        g<<N-nr;
    else
        g<<"0";
    return 0;
}
