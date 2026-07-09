#include<fstream>
#include<iostream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n,i,a,b;

int div(int st, int dr)
{
    int c;
    while(st%dr!=0)
    {
        c=st%dr;
        st=dr;
        dr=c;
    }
    return dr;
}

int main()
{
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>a>>b;
        fout<<div(a, b)<<"\n";
    }
    fin.close();
    fout.close();
    return 0;
}
