#include iostream
#include fstream
using namespace std;
ifstream g(euclid2.in);
ofstream gg(euclid2.out);
int algoritmEUCLID(int a, int b){
    int r=a%b;
    while(r){
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}
int main(){
    int n,a,b;
    gn;
    while(n0){
        gab;
        ggalgoritmEUCLID(a,b)n;
        n--;
    }
    return 0;
}
