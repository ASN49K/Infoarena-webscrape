#include<fstream.h>
int main() {
    int i,j,n,a,b,r;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    for(i=1;i<=n;i++){
        f>>a>>b;
        while(b!=0){
             r=a%b;
             a=b;
             b=r;
             }
        g<<a<<"\n";
    }
    
    f.close();
    g.close();
    return 0;
}                          
