#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int dx[4]={0, 0, 1, -1};
int dy[4]={1, -1, 0, 0};

void Citire(int m[102][102], int &n)
{
    ifstream f("lacuri.in");
    f>>n;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            f>>m[i][j];
        }
    }
    f.close();
}

void Bordare(int m[102][102], int n)
{
    for(int i=0; i<=n+1; i++)
    {
        m[0][i]=-1;
        m[n+1][i]=-1;
        m[i][0]=-1;
        m[i][n+1]=-1;
    }
}

void Afisare(int m[102][102], int n)
{
    for(int i=0; i<=n+1; i++)
    {
        for(int j=0; j<=n+1; j++)
        {
            cout<<setw(3)<<m[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}

int VerificareInterior(int m[102][102], int i, int j, int cnt)
{
//    cout<<"i - "<<i<<endl;
//    cout<<"j - "<<j<<endl;
//    cout<<"cnt - "<<cnt<<endl;
    int i1=i; int j1=j;
    for(i=i1; i<=i1+cnt; i++)
    {
        for(j=j1; j<=j1+cnt; j++)
        {
            if(m[i][j]!=1)
            {
                return 0;
            }
            else
            {
                m[i][j]=-2;
            }
        }
    }
    return 1;
}
int VerificareExterior(int m[102][102], int i, int j, int cnt)
{
    int i1=i;
    int j1=j;
    for(i; i<=i1+cnt+2; i++)
    {
        if(m[i][j]==1 || m[i][j+cnt+2]==1)
        {
            return 0;
        }
    }
    i=i1;
    for(j; j<=j1+cnt+2; j++)
    {
        if(m[i][j]==1 || m[i+cnt+2][j]==1)
        {
            return 0;
        }
    }
    return 1;
}

int VerificareLacPatrat(int m[102][102], int i, int j)
{
    int j1=j;
    int i1=i;
    int cnt1=0;
    int cnt2=0;
    while(m[i][++j]==1)
    {
        cnt1++;
    }
    j=j1;
    while(m[++i][j]==1)
    {
        cnt2++;
    }
    i=i1;
    if(cnt1==cnt2)
    {
        if(VerificareInterior(m, i, j, cnt1))
        {
            if(VerificareExterior(m, i-1, j-1, cnt1))
            {
                return 1;
            }
        }
    }
    return 0;
}

void StergereLacNePatrat(int m[102][102], int i, int j)
{
    int x, y;
    m[i][j]=-2;
    for(int k=0; k<4; k++)
    {
        x=i+dx[k];
        y=j+dy[k];
        if(m[x][y]==1)
        {
            StergereLacNePatrat(m, x, y);
        }
    }
}

int NumarLacuriPatrate(int m[102][102], int n, int &t)
{
    int nr=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(m[i][j]==1)
            {
                if(VerificareLacPatrat(m, i, j))
                {
                    nr++;
                }
                else
                {
                    t=0;
                    StergereLacNePatrat(m, i, j);
                }
            }
        }
    }
    return nr;
}

void Drum(int m[102][102], int n)
{
    ofstream g("lacuri.out");
    int t=1;
    g<<NumarLacuriPatrate(m, n, t)<<endl;
    if(t==1)
    {
        int c[2][102*102], p, u, x, y, x1, y1;
        c[0][0]=n;
        c[1][0]=n;
        p=0; u=1;
        m[n][n]=1;
        while(p<u)
        {
            x=c[0][p];
            y=c[1][p];
            for(int k=0; k<4; k++)
            {
                x1=x+dx[k];
                y1=y+dy[k];
                if(m[x1][y1]==0)
                {
                    c[0][u]=x1;
                    c[1][u]=y1;
                    m[x1][y1]=m[x][y]+1;
                    u++;
                }
            }
            p++;
        }
        x=1; y=1;
        int stop;
        while(x!=n || y!=n)
        {
            stop=0;
            g<<x<<" "<<y<<endl;
            for(int k=0; k<4 && stop==0; k++)
            {
                x1=x+dx[k];
                y1=y+dy[k];
                if(m[x1][y1]==m[x][y]-1)
                {
                    x=x1;
                    y=y1;
                    stop=1;
                }
            }
        }
        g<<n<<" "<<n<<endl;
    }

    g.close();
}


int main()
{
    int m[102][102], n;
    Citire(m, n);
    Bordare(m, n);
    Drum(m, n);

    return 0;
}
