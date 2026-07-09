#include <fstream>

using namespace std;
ifstream f ("euclid2.in");
ofstream g ("euclid2.out");
int n,a,b,r,i;
void solve (){
    while(1==1){
    r=a%b;
        if(r==0){
            g<<b<<'\n';
            break;}
        else
            a=b;
        b=r;
        }}

int main()
{f>>n;
    for(i=1;i<=n;i++){
            f>>a>>b;
        solve ();
    }

    return 0;
}
