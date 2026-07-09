#include <fstream>


using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int main(){
    int t;
    cin>>t;
    while(t--){
        int a, b;
        cin>>a>>b;
        while((a > 0) && (b > 0)){
            if(a > b)
                a = a%b;
            else b = b%a;
        }
        a = max(a, b);
        cout<<a<<'\n';
    }
    return 0;
}
