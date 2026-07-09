#include <iostream>
#include <fstream>

using namespace std;

ifstream in("nim.in");
ofstream out("nim.out");

int main()
{
    int t;
    in>>t;
    for(int i=1;i<=t;i++)
    {
        int n,rez=0;
        in>>n;
        for(int j=1;j<=n;j++)
        {
            int x;
            in>>x;
            rez=rez^x;
        }
        if(rez!=0)
            out<<"DA";
        else
            out<<"NU";
        out<<'\n';
    }
}
