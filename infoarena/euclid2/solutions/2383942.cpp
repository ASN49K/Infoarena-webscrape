#include <fstream>

using namespace std;

ifstream cin ("euclid2.in");
ofstream cout ("euclid2.out");

int main() {
    int n;
    cin>>n;
    for (int i=1; i<=n; i++){
        int a,b;
        cin>>a>>b;
        while(b){
            int t = a % b;
            a = b;
            b = t;
        }
        cout<<a<<'\n';
    }
    return 0;
}
