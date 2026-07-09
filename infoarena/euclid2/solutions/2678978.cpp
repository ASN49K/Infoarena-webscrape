#include <iostream>
using namespace std;

int main()
{
    int n; cin>>n;
    for(int i = 1; i<=n; i++){
        int a, b;
        cin>>a>>b;
        while(b){
            int r = a%b;
            a = b;
            b = r;
        }
        cout<<a<<endl;
    }
}
