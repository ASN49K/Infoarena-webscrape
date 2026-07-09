#include<fstream.h>

#define nmax 1100

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n, m, i, j, a[nmax], b[nmax], c[nmax], nr[nmax], max, in[nmax], imax;

void apel(int x, int y[])
{
    if(x==0) return;
    apel(in[x], y);
    g<<y[c[x]]<<' ';
}

int main()
{
    f>>n>>m;
    for(i=1; i<=n; i++) f>>a[i];
    for(j=1; j<=m; j++) f>>b[j];
    f.close();

    if(n>m){
        for(i=1; i<=m; i++)
            for(j=1; j<=n; j++) if(b[i]==a[j]) c[i]=j;
        
        nr[1]=1;
        for(i=2; i<=m; i++)
            for(j=1; j<i; j++) if( c[i]>c[j] && nr[i] < nr[j]+1 ){ nr[i]=nr[j]+1; in[i]=j; }
        
        for(i=1; i<=m; i++) if(nr[i]>max){ max=nr[i]; imax=i; }
        g<<max<<'\n';
        
        n=m;
        apel(imax, a);
    }
        else{
            for(i=1; i<=n; i++)
                for(j=1; j<=m; j++) if(b[i]==a[j]) c[i]=j;
            nr[1]=1;
            for(i=2; i<=m; i++)
                for(j=1; j<i; j++) if( c[i]>c[j] && nr[i] < nr[j]+1 ){ nr[i]=nr[j]+1; in[i]=j; }
        
            for(i=1; i<=m; i++) if(nr[i]>max){ max=nr[i]; imax=i; }
            g<<max<<'\n';
            apel(imax, b);
        }

    g.close();
    return 0;
}      
     
        
