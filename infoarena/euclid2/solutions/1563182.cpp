#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
const char *IN  = "euclid2.in";
const char *OUT = "euclid.out";

class Math{
    private :
        Math(){};
        ~Math(){};
    public :
        static int getGCD(int a,int b){
            return (a==0) ? b : getGCD(b%a,a);
        }
    };
int q,a,b;
int main(void){
    ifstream cin(IN);
    ofstream cout(OUT);
    cin>>q;
    while(q--){
        cin>>a>>b;
        cout<<Math::getGCD(a,b)<<endl;
    }
    return 0;
}
