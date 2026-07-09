#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int euclid(long a,long b)
{
   return(b)?euclid(b,a%b):a;
}
int main()
{
    int t;
    long a,b;
    fin>>t;
    for(int i=0;i<t;i++)
       {
           fin>>a>>b;
           fout<<euclid(a,b)<<'\n';

       }
    return 0;
}
