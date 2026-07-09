#include <fstream>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

int main(){
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");

    int a,b;in>>a>>b;
    int x[1025],y[1025];
    for(int i=0;i<a;i++){
        in>>x[i+1];
    }
    for(int i=0;i<b;i++){
        in>>y[i+1];
    }

    int m[1025][1025];
    for(int i=0;i<1025;i++){
        m[0][i]=0;
        m[i][0]=0;
    }

    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(x[i]==y[j]){
                m[i][j]=1+m[i-1][j-1];
            }else{
                m[i][j]=max(m[i-1][j],m[i][j-1]);
            }
        }
    }
    out<<m[a][b]<<"\n";
    stack<int> s;
    int i=a,j=b;
    while(m[i][j]){
        while(m[i][j]-m[i][j-1]!=1) j--;
        while(m[i][j]-m[i-1][j]!=1) i--;
        s.push(x[i]);
        i--;j--;
    }
    while(!s.empty()){
        int t=s.top();
        out<<t<<" ";
        s.pop();
    }
}




