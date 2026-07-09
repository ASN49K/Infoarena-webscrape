#include <fstream>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

void euclid( int a , int b)
{
    int i , j,t;

    while(a!=b)
    {
        if(a>b)
            a=a-b;
        if(b>a)
            b=b-a;

    }
    fout<<b<<endl;
}

int main()
{
    int a , b , t;
    fin>>t;
    for(int i=1;i<=t;i++)
    {
        fin>>a>>b;
        euclid(a,b);

    }
    return 0;
}
