#include <fstream>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

void euclid( int a , int b)
{
    int i , j,t,r,q;
        r=a%b;
    while(r!=0)
    {

        a=b;
        b=r;
        r=a%b;


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
