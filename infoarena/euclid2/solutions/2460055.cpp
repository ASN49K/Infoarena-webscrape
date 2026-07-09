#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int a,b,t,T,i;
int main()
{
    fin>>T;
    for(i=1;i<=T;i++)
    {fin>>a>>b;
    while(b)
    {
        t=a%b;
        a=b;
        b=t;
    }
    fout<<a<<"\n";}
}
