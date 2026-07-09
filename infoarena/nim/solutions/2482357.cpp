//#include <iostream>
#include <fstream>
using namespace std;
int n,a;
int main()
{
    ifstream cin("nim.in");
    ofstream cout("nim.out");
    int t;
    cin>>t;
    while(t){
        int x=0;
        t--;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a;
            x^=a;
        }
        if(x==0){
            cout<<"NU\n";
        }
        else
            cout<<"DA\n";
    }
    return 0;
}
