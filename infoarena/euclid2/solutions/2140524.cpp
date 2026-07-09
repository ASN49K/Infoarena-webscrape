#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n;
long long a,b,d;

int euclid(int x,int y){
    while(b!=0){
        d=a%b;
        a=b;
        b=d;
    }
    return a;
}

int main(){
    f>>n;
    for(int i=1;i<=n;i++){
        f>>a>>b;
        g<<euclid(a,b)<<endl;
    }
return 0;
}
