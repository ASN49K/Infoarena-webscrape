#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int euclid2(int a,int b)
{
    if(a<b){
        int aux = a;
        a = b;
        b = aux;
    }
    int rest;
    while(a%b!=0){
        rest = a%b;
        a = b;
        b = rest;
    }
    return b;

}
int main(){
    int n,a,b;
    f>>n;
    for(int i=0; i<n; i++){
        f>>a>>b;
        g<<euclid2(a,b)<<'\n';
    }
    return 0;
}
