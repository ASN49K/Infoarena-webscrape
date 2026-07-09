using namespace std;
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<iomanip>
#define pb push_back
ofstream fout("xmoto.out");
struct nod{
double a,b,k,q,v;};
nod a[50005];
double v;
vector<double> ans;
int N;
double L,sa,sb,sq,sk;

bool cmp(nod i, nod j)
{
    return (i.v<j.v);
}

void cit()
{
    int i,ii;
    ifstream fin("xmoto.in");
    fin>>N>>L;
    for(i=1;i<=N;i++)
    {
        fin>>a[i].a>>a[i].b>>a[i].k>>a[i].q>>a[i].v;
    }
    sort(a+1,a+1+N,cmp);
    /*for(i=1;i<=N;i++)
    {
        cout<<a[i].a<<" "<<a[i].b<<" "<<a[i].k<<" "<<a[i].q<<" "<<a[i].v<<"\n";
    }*/

    for(i=0;i<=N;i++)
    {
        sa=0;
        sb=0;
        sk=0;
        sq=0;
        for(ii=1;ii<=i;ii++)
        {
            sb+=a[ii].b;
            sq+=a[ii].q;
        }
        for(ii=i+1;ii<=N;ii++)
        {
            sa+=a[ii].a;
            sk+=a[ii].k;
        }
        if(sa+sb!=0)
        {
            v=(L-(sk+sq))/(sa+sb);
            if(v<=a[i+1].v || i==N)
            {
                if(v>a[i].v || i==0)
                {
                    ans.pb(v);
                }
            }
        }
       // cout<<L<<"\n";
       // cout<<sk<<" "<<sq<<" "<<sk+sq<<" "<<"\n";
        //cout<<sa<<" "<<sb<<" "<<sa+sb<<" "<<"\n\n\n";
    }
    fout<<ans.size()<<"\n";
    vector<double>::iterator it;
    setprecision(6);
    for(it=ans.begin();it<ans.end();it++)
    {
        fout<<fixed<<*it<<"\n";
    }
    fin.close();
}

int main()
{

    cit();

    fout.close();
    return 0;
}
