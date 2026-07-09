#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream be("nim.in");
    ofstream ki("nim.out");
    int t,xor_nim;
    be>>t;
    for(int k=0;k<t;k++)
    {
        xor_nim=0;
        int n;
        be>>n;
        for(int i=0;i<n;i++)
        {
            int x;
            be>>x;
            xor_nim=xor_nim^x;
        }
        if(xor_nim)
            ki<<"DA"<<'\n';
        else ki<<"NU"<<'\n';

    }
    return 0;
}
