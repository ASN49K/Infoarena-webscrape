#include<fstream>
using namespace std;
int n, a, b, r;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int main(){
    in>>n;
    for(;n--;){
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
