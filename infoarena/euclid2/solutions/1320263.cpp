#include<fstream>
using namespace std;
int n, a, b, i, r;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int main(){
    in>>n;
    for(i=1; i<=n; i++){
        in>>a>>b;
        while(b!=0){
            r=a%b;
            a=b;
            b=r;
        }
        out<<a<<"\n";
    }
return 0;
}
