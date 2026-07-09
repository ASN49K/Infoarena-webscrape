#include <fstream>
#include <vector>
#define Nmax 150005

using namespace std;
ofstream  fout("date.out");

int n,a[Nmax],nr=1;
vector <int> L[Nmax],L1[Nmax];

inline long long Cnt(int b, int t)
{
    int i,cnt=0;
    long long sol=0;
    vector <int> ::iterator it;
    for(i=1;i<=nr;++i)
    {
        cnt=0;
        for(it=L[i].begin();it!=L[i].end();++it)
        {
            if(((*it&(1<<b))>0) == t) ++cnt;
            else sol+=cnt;
        }
    }
    return sol;
}

inline void Split(int b, int t)
{
    int cnr=0,l0,l1,i;
    vector <int> ::iterator it;
    for(i=1;i<=nr;++i)
    {
        l0=l1=-1;
        for(it=L[i].begin();it!=L[i].end();++it)
        {
            if(((*it&(1<<b))>0) == t)
            {
                if(l0==-1) l0=++cnr;
                L1[l0].push_back(*it);
            }
            else
            {
                if(l1==-1) l1=++cnr;
                L1[l1].push_back(*it);
            }
        }
        L[i].clear();
    }
    nr=cnr;
    for(i=1;i<=nr;++i)
    {
        for(it=L1[i].begin();it!=L1[i].end();++it) L[i].push_back(*it);
        L1[i].clear();
    }
}

int main()
{
    int A0,A1,P,Q,R,Put,i,l,B=0;
    vector <int> ::iterator it;
    long long Solution=0;
    ifstream  fin("date.in");
    fin>>Put>>n>>A0>>A1>>P>>Q>>R;
    a[1]=A0; a[2]=A1;
    for(i=3;i<=n;++i)
        a[i]=(((1LL*a[i-2]*P)%Put)+((1LL*a[i-1]*Q)%Put)+R)%Put;
    for(i=1;i<=n;++i) L[1].push_back(a[i]);
    for(l=0;(1<<l)!=Put;++l);
    for(i=l-1;i>=0;--i)
    {
        //fout<<Cnt(i,0)<<" "<<Cnt(i,1)<<"\n";
        if(Cnt(i,0)>Cnt(i,1))
        {
            Solution+=Cnt(i,0);
            Split(i,0);
        }
        else
        {
            Solution+=Cnt(i,1);
            Split(i,1);
            B+=(1<<i);
        }
        /*for(int j=1;j<=nr;++j)
        {
            for(it=L[j].begin();it!=L[j].end();++it) fout<<*it<<" ";
            fout<<"\n";
        }*/
    }
    //fout<<B<<"\n";
    fout<<Solution;
    return 0;
}
