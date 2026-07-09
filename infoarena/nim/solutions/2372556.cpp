#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int T,N,rez,val;
int main()
{
    int i,j;
    fin>>T;
    for(i=1;i<=T;i++)
    {
        fin>>N;
        rez=0;
        for(j=1;j<=N;j++)
        {
            fin>>val;
            rez=rez^val;
        }
        if(rez==0)
            fout<<"NU\n";
        else
            fout<<"DA\n";
    }
}
