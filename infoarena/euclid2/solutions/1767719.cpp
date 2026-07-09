#include <fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int a,b,r,n;
int main()
{
    cin>>n;
    for(int i = 1 ; i <= n ; i++){
        cin>>a>>b;
        while(b){
            r=a%b;
            a=b;
            b=r;
        }
        cout<<a<<endl;
    }
    return 0;
}
