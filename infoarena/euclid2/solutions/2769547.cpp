#include <fstream>
#include <cmath>

std::ifstream cin("euclid2.in");
std::ofstream cout("euclid2.out");

int euclid(int a , int b){

    while(b != 0 && a != 0){
        int q = b, r = a;

        a > b   ? b = a %b,  a = q 
                : a = b % a, b = r;  
    }

    return std::max(a,b);
}

int main(){
    int n,a,b; cin>>n;

    for(int i = 0  ; i < n ; i++){
        cin>>a>>b;
        
        cout<<euclid(a,b)<<"\n";
    }
}

