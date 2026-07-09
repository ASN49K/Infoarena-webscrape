#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

void schimb(int &a,int &b){
    int aux;
    if(a<b){
        aux=a;
        a=b;
        b=aux;
    }
}

void euclid(int a,int b){
    int r;
    while(b>0){
        r=a%b;
        a=b;
        b=r;
    }
    out<<a<<'\n';
}

int main(){
    int t,x,y;
    in>>t;
    for(int i=1;i<=t;i++){
        in>>x>>y;
        euclid(x,y);
    }
    return 0;
}
