#include <fstream>
#include <vector>
using namespace std;

int n,m,s[1028][1028];
vector <int> a,b,c;

void citire(){
int i,j,x;
ifstream f("cmlsc.in");
f>>n>>m;
for (i=1;i<=n;i++) {
    f>>x;
    a.push_back(x);
}
for (i=0;i<m;i++){
    f>>x;
    b.push_back(x);
    for (j=0;j<n;j++){
        if (b[i]==a[j]) s[i+1][j+1]=s[i][j]+1;
            else {
                if (s[i][j+1]>s[i+1][j]) s[i+1][j+1]=s[i][j+1];
                                   else s[i+1][j+1]=s[i+1][j];
            }
    }
}
}

void cmlsc(){
int i,j,aux;
j=n;
i=m;
aux=s[i][j];
while (aux && (j||i)){
    while (i && s[i-1][j]==s[i][j]) i--;
    c.push_back(b[i-1]); aux--; i--;
    while (j && s[i][j-1]==s[i][j]) j--;
    c.push_back(a[j-1]); aux--; j--;
}
}

void tiparire(){
ofstream g("cmlsc.out");
g<<s[m][n]<<'\n';
while (!c.empty()) {
    g<<c.back()<<' '; c.pop_back();
}
}

int main(){
citire();
cmlsc();
tiparire();
return 0;
}
