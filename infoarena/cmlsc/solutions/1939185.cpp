#include <fstream>
#include <vector>
#include <cstdio>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,i,j,el,actual,total;
short int viza[1025],vizb[1025],vera[1025],verb[1025],sol1[1025],sol2[1025];
vector <int> a;
vector <int> b;
vector <int> v[1025];
vector <int> c[1025];
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++) f>>el,a.push_back(el),viza[el]=1,v[el].push_back(i);
    for(i=1;i<=m;i++) f>>el,b.push_back(el),vizb[el]=1,c[el].push_back(i);
    int minim1=0,minim2=0,nr=0;
    for(i=0;i<n&&minim2<n;i++)
    {
        actual=a[i];
        if(c[actual].size()>1) while(c[actual][0]<minim2) c[actual].erase(c[actual].begin());
        if(viza[actual]&&vizb[actual]&&v[actual][0]>minim1&&c[actual][0]>minim2)
        {
            sol1[++nr]=actual;
            minim1=v[actual][0];
            minim2=c[actual][0];
            v[actual].erase(v[actual].begin());
            c[actual].erase(c[actual].begin());
        }
    }
    total=nr;
    minim1=0,minim2=0,nr=0;
    for(i=0,j=0;i<max(n,m);i++,j++)
    {
        if(i<a.size())
        {
            if(!vera[a[i]]) v[a[i]].erase(v[a[i]].begin(),v[a[i]].end()),vera[a[i]]++;
            v[a[i]].push_back(i+1);
        }
        if(j<b.size())
        {
            if(!verb[b[i]]) c[b[i]].erase(c[b[i]].begin(),c[b[i]].end()),verb[b[i]]++;
            c[b[i]].push_back(i+1);
        }
    }
    for(i=0;i<m&&minim1<n;i++)
    {
        actual=b[i];
        if(v[actual].size()>1) while(v[actual][0]<minim1) v[actual].erase(v[actual].begin());
        if(viza[actual]&&vizb[actual]&&v[actual][0]>minim1&&c[actual][0]>minim2)
        {
            sol2[++nr]=actual;
            minim1=v[actual][0];
            minim2=c[actual][0];
            v[actual].erase(v[actual].begin());
            c[actual].erase(c[actual].begin());
        }
    }
    if(total>nr)
    {
        g<<total<<'\n';
        for(i=1;i<=total;i++) g<<sol1[i]<<" ";
    }
    else
    {
        g<<nr<<'\n';
        for(i=1;i<=nr;i++) g<<sol2[i]<<" ";
    }
    return 0;

}
