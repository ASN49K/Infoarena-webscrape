#include <fstream>
#include <vector>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

struct matrix
{
    int a;
    short h;
};

matrix a[1025][1025];

vector<int> o;

void back(int f, int g, vector<int>& x, vector<int>& y)
{
        if(x[f]==y[g] && x[f]!=0)o.push_back(x[f]);
        if(a[f][g].h==1) back(f-1,g,x,y);
        if(a[f][g].h==2) back(f,g-1,x,y);
        if(a[f][g].h==3) back(f-1,g-1,x,y);
}

int main()
{
    int n,m;
    fin>>n>>m;
    vector<int> x(n+1);
    vector<int> y(m+1);
    int i,j;
    for(i=1;i<=n;i++)
        fin>>x[i];
    for(j=1;j<=m;j++)
        fin>>y[j];

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(x[i]==y[j])
            {
                a[i][j].a=a[i-1][j-1].a+1;
                a[i][j].h=3;
            }
            else
            {
                if(a[i-1][j].a>a[i][j-1].a)
                {
                    a[i][j].a=a[i-1][j].a;
                    a[i][j].h=1;
                }
                else
                {
                    a[i][j].a=a[i][j-1].a;
                    a[i][j].h=2;
                }
            }
        }
    }

    /*for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            cout<<a[i][j].a<<" ";
        }
        cout<<"\n";
    }*/

    back(n,m,x,y);
    fout<<o.size()<<"\n";
    for(auto it=o.rbegin();it!=o.rend();it++) fout<<*it<<" ";
}
