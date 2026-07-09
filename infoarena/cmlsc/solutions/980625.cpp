#include <fstream>
using namespace std;
ifstream f("rmq.in");
ofstream g("rmq.out");
int n, m, i, j, d[100010][20], p[100010], a, x, y;

int minim(int x, int y){
    if(x<y)
        return x;
    return y;
}

int main(){
    f>>n>>m;
    //d[i][j]=min din vector dintre pozitiile i+0 si i+(2^j-1)
    for(i=1; i<=n; i++)
        f>>d[i][0];
    //precalculez puterile lui 2
    for(i=2; i<100001; i++)
        p[i]=p[i/2]+1;
    for(j=1; j<=p[n]; j++)
        for(i=1; i<=n; i++)
        {
            d[i][j]=d[i][j-1];
            if(i+(1<<(j-1))<=n && d[i+(1<<(j-1))][j-1]<d[i][j])
                d[i][j]=d[ i+(1<<(j-1)) ][j-1];
        }
    /*for(i=1; i<=n; i++)
    {
        for(j=0; j<=p[n]; j++)
            g<<d[i][j]<<' ';
        g<<"\n";
    }*/
    for(i=1; i<=m; i++)
    {
        f>>x>>y;
        a=p[y-x+1];
        g<<minim(d[x][a], d[y-(1<<a)+1][a])<<"\n";
    }
    return 0;
}
