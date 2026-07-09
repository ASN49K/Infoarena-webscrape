#include <fstream>

using namespace std;

ifstream cin("nim.in");
ofstream cout("nim.out");
int n;
int m,x,y;
int main(){
    cin>>n;
    for(int i=1;i<=n){
        cin>>m;
        cin>>x;
        int s= 0;
        for(int j=1;j<m;++j){
            cin>>y;
            s = x^y;
        }
        if(s==0)
            cout<<"NU";
        else cout<<"DA";
    }
}
