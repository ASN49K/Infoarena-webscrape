#include <fstream>

using namespace std;


ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int euclid( int a , int b)
{
    if(b==0)
        return a;
    else
        return euclid (b,a%b);
}

int main()
{
    int a , b , t;
    fin>>t;
    for(int i=0;i<t;i++)
    {
        fin>>a>>b;
        fout<< euclid(a,b)<<'\n';

    }
    return 0;
}
