#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int n,x,sum;
int main()
{
    int t;
    fin>>t;
    while(t--)
    {
        fin>>n;
        sum=0;
        for(int i=1;i<=n;i++)
        {
            fin>>x;
            sum=sum^x;
        }
        if(sum==0) fout<<"NU"<<"\n";
        else fout<<"DA"<<"\n";
    }
   }
