#include <fstream>
 
using namespace std;
    ifstream file("euclid2.in");
    ofstream file_o("euclid2.out"); 
 
int euclid2(int a,int b){
    if (b==0)return a;
    else return euclid2(b,a%b);
}
 
 
 
int main(){

    int it,a,b;
    file>>it;
    for(int i=0;i<it;i++){
        file>>a>>b;
        file_o<<euclid2(a,b)<<endl;
    }
 
}