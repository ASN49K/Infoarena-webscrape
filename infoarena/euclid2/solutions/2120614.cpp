#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int euclid(long a,long b)
{
    while(b>0)
    {
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    int t;
    long a,b;
    fin>>t;
    for(int i=0;i<t;i++)
       {
           fin>>a>>b;
           fout<<euclid(a,b);

       }
    return 0;
}
