#include<fstream.h>

ifstream f("euclid.in");
ofstream g("euclid.out");

int n, m, i;

int main()
{
    f>>n>>m;
    f.close();
    
    while(m!=0){
        i=n%m;
        n=m; 
        m=i;
    }

    g<<n;
    g.close();
    return 0;
}        
