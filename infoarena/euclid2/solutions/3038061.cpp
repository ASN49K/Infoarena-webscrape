#include <fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int n, x, y, i, j, r;
int main () {
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>x>>y;
        while(y){
            r=x%y;
            x=y;
            y=r;
        }
        cout<<x<<"\n";
    }
}
