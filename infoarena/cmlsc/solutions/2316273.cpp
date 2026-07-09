//
//  main.cpp
//  1.11
//
//  Created by Petcu Iancu on 11/01/2019.
//  Copyright © 2019 Petcu Iancu. All rights reserved.
//

#include <iostream>
#include<fstream>
using namespace std;
int v[1030][1034],a[1034],b[1034],c[1034];
int main() {
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");
    int i,j,n,m,k=1;
    //cout<<"n=";
    cin>>n;
    //cout<<"m=";
    cin>>m;
    //cout<<"sirul n:";
    for(i=1;i<=n;i++)
        cin>>a[i];
   // cout<<"sirul m:";
    for(j=1;j<=m;j++)
        cin>>b[j];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            v[i][j]=max(v[i-1][j],v[i][j-1]);
            if(a[i]==b[j])
                v[i][j]=max(v[i][j],v[i-1][j-1]+1);
        }
    }
    i=n;
    j=m;
    cout<<v[n][m]<<endl;
    while(i>0 && j>0 && v[i][j]>0)
    {
        if(v[i][j]-1==v[i-1][j-1])
        {
            i--;
            j--;
            cout<<a[i]<<" "<<b[j]<<" "<<i<<" "<<j<<endl;
            c[k]=a[i+1];
            k++;
        }
        else
        {
            if(v[i][j]==v[i-1][j])
            {
                i--;
            }
            else
            {
                if(v[i][j]==v[i][j-1])
                {
                    j--;
                }
            }
        }
    }
    for(i=k-1;i>0;i--)
        cout<<c[i]<<" ";
    cout<<endl;
    return 0;
}
