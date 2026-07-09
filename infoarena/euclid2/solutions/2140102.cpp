#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,d,n;


int Euclid(int x,int y){
    while(a%d!=0 || b%d!=0){
        d=d/2;
    }
    return d;
}

int main(){
    f>>n;
    for(int i=1;i<=n;i++){
        f>>a>>b;
        if(a<=b)d=a;
        else d=b;
        g<<Euclid(a,b)<<endl;
    }
return 0;
}
