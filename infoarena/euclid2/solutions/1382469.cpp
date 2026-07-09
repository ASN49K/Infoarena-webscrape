#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
long long a,b;
int t;
void alg()
{
   long long r=1;
    while(r)
    {
        r=a%b;
        a=b;
        b=r;
    }
    fout<<a<<'\n';
}
void citire()
{
    fin>>t;
    for(int a1=1;a1<=t;a1++)
    {
        fin>>a>>b;
        alg();
    }

}
int main()
{
    citire();
}
