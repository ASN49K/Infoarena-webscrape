#include <fstream.h>
int T,a,b;
int euclid(int x,int y){
    int r;
   while (y>0){r=x%y; x=y; y=r; }
    return x;
}
 
int main(){
   int i;
    ifstream f("euclid2.in");
    f>>T;
    ofstream g("euclid2.out");
   for (i=1;i<=T;i++)
   { f>>a>>b;
     g<<euclid(a,b)<<"\n";
    }
    f.close();
    g.close();
    return 0;
}
