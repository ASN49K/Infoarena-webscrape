#include<fstream>
using namespace std;

int main(){
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int t;
    f>>t;
    for(int i=0;i<t;++i){
        int a,b,c;
        f>>a>>b;
        while(b){
            c=a%b;
            a=b;
            b=c;
        }
        g<<a<<"\n";
    }
    return 0;
}
