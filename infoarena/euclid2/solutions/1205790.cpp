#include<fstream>
using namespace std;
int T, a, b, r;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int main(){
    in>>T;
    for(;T--;){
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
