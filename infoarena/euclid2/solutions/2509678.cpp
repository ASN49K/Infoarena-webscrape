#include <fstream>
using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int n;
long long a, b;
int main(){
    cin>>n;
    while(n){
        cin>>a>>b;
        while(a!=b){
                if(a>b) a-=b;
                else b-=a;
        }
        cout<<a<<endl;
        n--;
    }
    return 0;
}
