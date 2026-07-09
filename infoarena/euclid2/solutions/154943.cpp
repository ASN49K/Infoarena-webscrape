#include<fstream.h>

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int n, m, i, t, j;

int main()
{
    f>>t;
    for(j=1; j<=t; j++){
        f>>n>>m;
        while(m!=0){
        i=n%m;
        n=m; 
        m=i;
        }
        g<<n<<'\n';
    }

    f.close();
    g.close();
    return 0;
}        
