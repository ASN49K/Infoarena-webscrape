#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
long long t,a,b,c;
int euclid(long long a,long long b )
{
long long c=a%b;
if(c!=0){
a=b;
b=c;
return euclid(a,b);}
else return b;

}
int main()
{
    fin>>t;
    for(int i=1;i<=t;i++)
    {
    fin>>a>>b;
    fout<<euclid(a,b)<<endl;

    }
    return 0;
}
