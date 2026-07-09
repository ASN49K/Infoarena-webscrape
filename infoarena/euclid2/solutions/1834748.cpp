#include <fstream>
using namespace std;

ifstream cin ("euclid2.in");
ofstream cout ("euclid2.out");

long long A,B,T,r;

int main(){
    cin>>T;
    for (int i=1; i<=T; i++) {
        cin>>A>>B;
        while (B!=0){
        r=A%B;
        A=B;
        B=r;
        }
        cout<<A<<"\n";
    }
    return 0;
}
