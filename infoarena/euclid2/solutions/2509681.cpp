#include <fstream>
using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int n;
long long a, b, r;
int main(){
    cin>>n;
    while(n){
        cin>>a>>b;
        while(b!=0){
                r=a%b;
                a=b;
                b=r;
        }
        cout<<a<<endl;
        n--;
    }
    return 0;
}
