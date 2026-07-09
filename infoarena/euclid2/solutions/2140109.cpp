#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,d,n;

int main(){
    f>>n;
    for(int i=1;i<=n;i++){
        f>>a>>b;
        while(b!=0){
            d = a % b;
            a = b;
            b = d;
        }
        g<<a<<endl;
    }
return 0;
}
