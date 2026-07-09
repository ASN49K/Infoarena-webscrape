#include <fstream>
using namespace std;
int main(){
    int T,c,D,I,R,a,b;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>T;
c=1;
while(c<=T){
 f>>a>>b;
    D=a;
    I=b;
    R=D%I;
    while (R!=0){
        D=I;
        I=R;
        R=D%I;
    }

    g<<I<<endl;
    c++;

}






}
