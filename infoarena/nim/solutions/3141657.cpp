#include <fstream>

using namespace std;

ifstream cin("nim.in");
ofstream cout("nim.out");
int n;
int m,x,y;
int main(){
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>m;
        cin>>x;
        int s= 0;
        for(int j=1;j<m;++j){
            cin>>y;
            s = (x%2)^(y%2);
            x= s;
        }
        if(s==0)
            cout<<"NU"<<endl;
        else cout<<"DA"<<endl;
    }
}
