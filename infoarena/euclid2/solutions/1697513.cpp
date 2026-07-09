#include<fstream>

using namespace std;

ifstream fin("");
ofstream fout("");

int cmmdc(int a, int b)
{
    int r;

    while (b!=0 )
    {
        r=a%b;
        a=b;
        b=r;
    }

    return a;
}

int main()
{
    int n,a,b,i;

    fin>>n;

    for (i=1;i<n;i++)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b);
    }

    return 0;
}
