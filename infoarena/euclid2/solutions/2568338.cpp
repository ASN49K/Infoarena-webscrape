#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("expresie7.in");
ofstream fout("expresie7.out");

int f1(int x,int y, int v[])
{
    int smax=v[x],s=v[x];
    if(s<0)
        s=0;
    for(int i=x+1;i<=y;i++)
    {
        s=s+v[i];
        if(s>smax)
            smax=s;
        if(s<0)
            s=0;
    }
return smax;

}
int main()
{
    char c,oper='+';
    int nr[100],n_nr=0,n=0,id=1,i, pr[50],n_pr=0,x;
    while (fin>>c){
        if (c==','||c==')'||c==']')
        {
            if(oper=='-') n=-n;
            nr[++n_nr]=n;
            n=0;
            oper='+';
        }
        if (c=='(')
            pr[++n_pr]=n_nr+1;
        if (c==')')
        {
            x=f1(pr[n_pr],n_nr,nr);
            n_nr=pr[n_pr]-1;
            n_pr--;
            nr[++n_nr]=x;
        }
        if (c=='-') oper='-';
        if(c>='0'&&c<='9')
            n=n*10+c-'0';
    }
    if (n!=0)
        if(oper=='-'){
            n=-n;
            nr[++n_nr]=n;
        }
    for(i=1;i<=n_nr;i++) fout<<nr[i]<<" ";
    return 0;
}
