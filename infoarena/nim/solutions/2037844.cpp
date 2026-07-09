#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream cin("nim.in");
    ofstream cout("nim.out");
    int n,i,s=0,t,j,a;
    cin>>t;
    for(i=1;i<=t;i++){
        cin>>n;
        s=0;
        for(j=1;j<=n;j++){
            cin>>a;
            s=s^a;
        }
        if(s>0){
            cout<<"DA"<<'\n';
        }
        else
            cout<<"NU"<<'\n';
    }
    return 0;
}
