#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("alee.in");
ofstream fout("alee.out");
int a[175][176],n,m;
struct coord{int x,y;};
coord c[175*175];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

void citire()
{
    fin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        fin>>x>>y;
        a[x][y]=-1;
    }
}
int interior(int x,int y)
{
    if(x>0&&x<=n&&y<=n&&y>0) return 1;
    return 0;
}
void lee(int x,int y)
{
    int p,u;
    p=u=1;
    c[p].x=x;
    c[p].y=y;
    while(p<=u)
    {
        x=c[p].x;
        y=c[p].y;
        p++;
        for(int i=0;i<=3;i++)
        {
            int xv=x+dx[i];
            int yv=y+dy[i];
            if(interior(xv,yv)==1&&a[xv][yv]==0)
            {
                a[xv][yv]=a[x][y]+1;
                u++;
                c[u].x=xv;
                c[u].y=yv;


            }


        }

    }
}
int main()
{
   citire();
   int x1,y1,x2,y2;
   fin>>x1>>y1>>x2>>y2;
   a[x1][y1]=1;
   lee(x1,y1);
   fout<<a[x2][y2];

    return 0;
}
