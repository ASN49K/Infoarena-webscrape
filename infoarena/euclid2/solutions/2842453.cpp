#include <fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int n,a,b;
int euclid(int a,int b){
    while(a!=b){
        if(a>b)a=a-b;
        else b=b-a;
    }
    return a;
}
int main()
{
    cin>>n;
    while(n){
        cin>>a>>b;
        if(a==b)cout<<a<<'\n';
        else if(a==b+1 || b==a+1)cout<<"1"<<'\n';
        else if(a%b==0)cout<<b<<'\n';
        else if(b%a==0)cout<<a<<'\n';
        else cout<<euclid(a,b)<<'\n';
        n--;
    }
    return 0;
}
