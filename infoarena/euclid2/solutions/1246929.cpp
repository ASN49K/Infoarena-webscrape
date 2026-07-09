#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int i,T,a,b,r;
int main()
{
    fin>>T;
    for(i=1;i<=T;i++)
    {
       fin>>a>>b;
       while(b)
       {
           r=a%b;
           a=b;
           b=r;
       }

    fout<<a<<"\n";
    }
    return 0;
}
