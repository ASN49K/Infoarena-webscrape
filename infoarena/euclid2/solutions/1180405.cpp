#include<fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int T;

int main () {

    int a,b,r;
    in>>T;
    for(int i=1;i<=T;i++){
        in>>a>>b;
        r=1;
        while(r) {
            r=a%b;
            a=b;
            b=r;
        }
        out<<a<<'\n';
    }
    in.close();
    out.close();
    return 0;

}
