#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("nim.in");
ofstream fout ("nim.out");

int main()
{
    int t,n,x,a;
    fin>>t;
    for(int i = 0 ; i < t ; i++)
    {
        a=0;
        fin>>n;
        for(int j = 0; j < n; j++)
        {
            fin>>x;
            a^=x;
        }
        if(!a) fout<<"NU"<<endl;
        else fout<<"DA"<<endl;
    }
}
