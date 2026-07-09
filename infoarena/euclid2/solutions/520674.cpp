#include <fstream.h>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int euclid(int a, int b){
    int m;
    while(b != 0){
            m = a % b;
            a = b;
            b = m;        
    }    
    return a;
}


void read(){
     int n, a, b;
     in>> n;
     for(int i = 0; i < n; i++){
             in>> a>> b;
             out<< euclid(a,b)<< "\n";
     }          
}


int main(){    
    read();    
    return 0;    
}
