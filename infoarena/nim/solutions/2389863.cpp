#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");

int main()
{   int n,t,x,a;
    fin>>t;
    while(t--)
    {
        fin>>n;
        a=0;
        for(int i=1; i<=n; i++)
        {
            fin>>x;
            a=a^x;
        }
        if(a) fout<<"DA";
        else fout<<"NU";
        fout<<endl;
    }
    return 0;
}
