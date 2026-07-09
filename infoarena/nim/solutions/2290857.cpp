#include<fstream>
using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int n,i,s,x,sol,t;
int main()
{
    fin>>t;
    for(;t--;)
    {
        fin>>n;fin>>sol;
        for(i=1;i<n;i++){fin>>x;sol^=x;}
        if(sol!=0) fout<<"DA\n";else fout<<"NU\n";
    }
}
