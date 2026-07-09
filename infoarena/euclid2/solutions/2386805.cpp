#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
long long t,a,b,c;
int euclid(long long a,long long b )
{
while (b!=0){
long long c=a%b;
a=b;
b=c;
}
return a;

}
int main()
{
    fin>>t;
    for(int i=1;i<=t;i++)
    {
    fin>>a>>b;if (a<b) swap(a,b);
    fout<<euclid(a,b)<<endl;

    }
    return 0;
}
