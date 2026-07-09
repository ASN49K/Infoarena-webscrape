#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <iomanip>
#define ll long long
using namespace std;
ifstream fin("nim.in");
ofstream gout("nim.out");
int main()
{
    ios_base::sync_with_stdio(false);
    fin.tie(0);
    gout.tie(0);
    int salut,n,a,x;
    fin>>salut;
    while(salut--)
    {
        fin>>n;
        a=0;
        while(n--)
        {
            fin>>x;
            a^=x;
        }
        if(!a)gout<<"NU\n";
        else gout<<"DA\n";
    }
    return 0;
}
