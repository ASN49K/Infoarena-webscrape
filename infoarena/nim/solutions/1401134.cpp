#include<fstream>
using namespace std;
int T, n, x, y;
ifstream in("nim.in");
ofstream out("nim.out");
int main(){
    in>>T;
    while(T--){
        in>>n;
        in>>y;
        for(n=n-1;n--;){
            in>>x;
            y^=x;
        }
        y==0?out<<"NU":out<<"DA";
    }
return 0;
}
