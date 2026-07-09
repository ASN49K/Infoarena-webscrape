#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int T;
int cmmdc(int a,int b)
{
    if(b==0) return a;
    else return cmmdc(a,a%b);
}
void citire()
{
    int a,b;
    fin>>T;
    for(int i=1;i<=T;i++)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<"\n";
    }
}
int main()
{
    citire();
}
