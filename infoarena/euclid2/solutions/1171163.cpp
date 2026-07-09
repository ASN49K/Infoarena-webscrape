#include<fstream>
using namespace std;
int n, x, y, r;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int main(){
    in>>n;
    for(;n--;){
        in>>x>>y;
        while(y!=0){
            r=x%y;
            x=y;
            y=r;
        }
        out<<x<<"\n";
    }
return 0;
}
