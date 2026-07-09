#include <fstream>
#include <iostream>
#include <stack>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int l1,l2,V1[1030],V2[1030],M[1030][1030];

stack<int> S;

void read(){
    in>>l1>>l2;
    for(int i=1;i<=l1;i++){
        in>>V1[i];
    }
    for(int i=1;i<=l2;i++){
        in>>V2[i];
    }
}
void solve(){
    for(int i=1;i<=l1;i++){
        for(int j=1;j<=l2;j++){
            if(V1[i]==V2[j]){
                M[i][j]=M[i-1][j-1]+1;
            }
            else{
                M[i][j]=max(M[i-1][j],M[i][j-1]);
            }
        }
    }
}
void drum(){
    int sx=l1,sy=l2;
    while(sx!=1){
        if(M[sx][sy]==M[sx-1][sy-1]+1){
            S.push(V1[sx]);
            sx--;
            sy--;
        }
        else if(M[sx][sy]==M[sx-1][sy]){
            sx--;
        }
        else if(M[sx][sy]==M[sx][sy-1]){
            sy--;
        }
    }
}
void write(){
    out<<M[l1][l2]<<"\n";
    drum();
    while(!S.empty()){
        out<<S.top()<<" ";
        S.pop();
    }
}
int main()
{
    read();
    solve();
    write();
    return 0;
}
