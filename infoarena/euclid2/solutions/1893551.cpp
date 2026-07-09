#include <fstream>
#define NMAX 100003
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int T,a,b,i;
int euclid(int a,int b);
int main()
{
       fin>>T;
       for(i=1;i<=T;i++)
       {
           fin>>a>>b;
           fout<<euclid(a,b)<<'\n';
       }

}
int euclid(int a,int b)
{
    if(b==0) return a;
    return euclid(b,a%b);
}
