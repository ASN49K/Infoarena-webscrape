// algoritmul lui euclid.cpp : Defines the entry point for the console application.
//

#include <fstream.h>
int n,a,b;
int euclid(int x,int y){
    int r;
   while (y){r=x%y; x=y; y=r; }
    return x;
}
 
int main(){
   int i;
    ifstream f("euclid2.in");
    fin>>n;
    ofstream g("euclid2.out");
   for (i=1;i<=n;i++)
   { fin>>a>>b;
     f<<euclid(a,b)<<'\n';
    }
    f.close();
    g.close();
    return 0;
}