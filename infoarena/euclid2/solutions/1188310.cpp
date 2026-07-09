#include <fstream>
#include <cmath>
using namespace std;
int cmmdc(int a, int b){
    a=abs(a);
    b=abs(b);
    if (b>a)return cmmdc(b,a);
    else{
        int r=a%b;
        while (r!=0){
            a=b;
            b=r;
            r=a%b;
        }
        return b;
    }
}
int main(){
    int x,y,n;
    fstream f("euclid2.in",ios::in);
    fstream g("euclid2.out",ios::out);
    f>>n;
    while (n>0){
        n--;
        f>>x>>y;
        g<<cmmdc(x,y);
    }
    f.close();
    g.close();
}
