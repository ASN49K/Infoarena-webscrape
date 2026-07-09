#include<fstream>
using namespace std;
int T, n, x, y, i;
ifstream in("nim.in");
ofstream out("nim.out");
int main(){
    in>>T;
    while(T--){
        in>>n;
        in>>y;
        n--;
        for(i=1;i<=n;i++){
            in>>x;
            y^=x;
        }
        y==0?out<<"NU\n":out<<"DA\n";
    }
return 0;
}
