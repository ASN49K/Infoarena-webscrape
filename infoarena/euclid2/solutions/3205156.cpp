#include <fstream>
#define cin fin
#define cout fout
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n,a,b;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        while(b!=0){
            int r=a%b;
            a=b;
            b=r;
        }
        cout<<a<<endl;
    }
    return 0;
}
