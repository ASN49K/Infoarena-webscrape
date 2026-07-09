#include <fstream>

using namespace std;
ifstream fin("euclid.in");
ofstream fout("euclid.out");
int i,k,a,b,r;
int main()
{
    fin>>k;
    for(i=1;i<=k;i++)
    {
       fin>>a>>b;
       while(b!=0)
       {
           r=a%b;
           a=b;
           b=r;
       }

    fout<<a<<" ";
    }
    return 0;
}
