#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <deque>
#include <algorithm>
#define ll long long

using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
int n,i,j,cnt,xorr,x,t;

int main()
{
    f>>t;
    while(t)
    {
        f>>n;
        xorr=0;
        for(i=1;i<=n;i++)
        {
            f>>x;
            xorr^=x;
        }
        if(xorr>0) g<<"DA\n";
        else g<<"NU\n";
        t--;
    }
    return 0;
}
