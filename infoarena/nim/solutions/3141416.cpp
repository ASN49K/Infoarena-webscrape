#include <fstream>
using namespace std;
ifstream cin("nim.in");
ofstream cout("nim.out");
int i, j, n, m, sum, ant, curr, t, x;
/*
int nrbit(int x){
    int nr=0;
    for(int i=0; (1<<i)<=x ;i++){
        if(x & (1<<i)){
            nr+=(1<<i);
        }
    }
    return nr;
}
*/
/*
int xorr(int a, int b){
    int s=0;
    for(int i=0;(1<<i)<=max(a, b); i++){
        if( (a & (1<<i)) != (b & (1<<i)) ){
           s+=(1<<i);
        }
    }
    return s;
}
*/
int main() {
    cin>>t;
    while(t--){
        ant=curr=sum=0;
        cin>>n;
        cin>>x;
        sum=x;
        for(i=1;i<n;i++){
            cin>>x;
            sum^=x;
        }
        if(sum>0)
            cout<<"DA"<<"\n";
        else
            cout<<"NU"<<"\n";
    }


}
