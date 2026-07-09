#include<iostream>
#include<vector>

using namespace std;

int n,v[100005];

vector<int> a[100005];

int main(){
    cin>>n;

    for(int i= 1;i<=n;i++)
        cin>>v[i];

    for(int i=0;i<=n;i++){
        a[i].resize(v[i]);
        for(int j=0;j<v[i];j++)
            cin>>a[i][j];
    }

}
