#include<fstream>
using namespace std;
int main(){
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    long long int t,a,b;
    in>>t;
    for(long long int i=1;i<=t;i++){
        in>>a>>b;
        long long int c=a%b;
        while(c){
            a=b;
            b=c;
            c=a%b;
        }
        out<<b<<'\n';
    }
}
