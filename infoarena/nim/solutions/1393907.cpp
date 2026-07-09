#include<fstream>
using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int n,s;
long long t;
int main()
{
    fin>>n;
    long long b;
    for(int a1=1;a1<=n;a1++)
    {
        fin>>t;
        s=0;
        for(int a2=1;a2<=t;a2++)
        {
            fin>>b;
            if(b==1) s++;
            else break;
        }
        if(s%2==0)
        {
            fout<<"Da"<<'\n';
        }
        else fout<<"Nu"<<'\n';
    }
}
