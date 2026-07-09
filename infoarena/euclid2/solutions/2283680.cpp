#include <iostream>
using namespace std;

int main(){

    int n , v[10005], i , aux ,sortat=0;
    cin>>n;
    for(i=1 ; i<=n ; i++){
        cin>>v[i];
    }
    while(sortat==0){
            sortat=1;
    for(i=1 ; i<n ; i++){
        if(v[i]<v[i+1]){
            sortat=0;
            aux=v[i];
            v[i]=v[i+1];
            v[i+1]=aux;
        }
    }
    }
    for(i=1 ; i<=n ; i++){
        cout<<v[i]<<" ";
    }
    return 0;
}

