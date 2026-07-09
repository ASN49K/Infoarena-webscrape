#include <iostream>
#include <fstream> 

using namespace std;

int euclid(int a,int b){
    if(b==0)
        return a;
    return euclid(b,a%b);
}

int main(){

    ifstream in("euclid2.in");   
    ofstream out("euclid2.out");
    
    int t,a,b,i;
    in>>t;
    for(int i=0;i<t;i++){
        in>>a>>b;
        out<<euclid(a,b)<<"\n";
    }
    
    
    in.close();
    out.close();
    return 0;
}