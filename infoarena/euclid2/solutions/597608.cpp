#include<fstream>
using namespace std;
int cmmmdc(int a,int b){
    if(!b)
    return a;
    else return cmmmdc(b,a%b);
}
int main (){
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int t,i,j;
    in>>t;
    for(;t;t--){
    in>>i>>j;
    out<<cmmmdc(i,j)<<"\n";
    }
    in.close();
    out.close();
    return 0;
}
