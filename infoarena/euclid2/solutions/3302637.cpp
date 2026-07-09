#include<fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

void run() {
    int a,b;
    cin>>a>>b;
    int r;
    while (b!=0) {
        r=b;
        b=a%b;
        a=r;
    }
    cout<<a;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        run();
        cout<<"\n";
    }
}