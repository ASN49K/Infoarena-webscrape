#include <fstream>

std::ifstream cin("euclid2.in");
std::ofstream cout("euclid2.out");

int euclid(int a , int b){
    while(a%b != 0){
        if(a > b) a %= b;
        else b %= a;
    }

    if(a>b) return b ; else return a;
}

int main(){
    int n; cin>>n;

    int a , b;

    for(int i = 0  ; i < n ; i++){
        cin>>a>>b;
        
        cout<<euclid(a,b)<<"\n";
    }
}

