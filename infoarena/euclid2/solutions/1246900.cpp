#include <fstream>

using namespace std;
ifstream fin("euclid.in");
ofstream fout("euclid.out");
int i,T,a,b,r;
int main()
{
    fin>>T;
    for(i=1;i<=T;i++)
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
