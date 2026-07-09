#include<iostream>

using namespace std;

int main(){
    int a[100][100];

    int n;

    cin>>n;

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    int m,x,y;
    cin>>m;

    for(int i=0;i<m;i++){
        cin>>x>>y;
        if(a[x][y]==1)
            cout<<"DA"<<'\n';
        else
            cout<<"NU"<<'\n';
    }

    return 0;
}
