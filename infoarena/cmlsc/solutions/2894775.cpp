#include <fstream>
using namespace std;

int main() {
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int n,m,max=0,k=1;
cin>>n>>m;
int a[1024],b[1024],c[1024];
for (int i=1; i<=n; i++){
    cin>>a[i];
}
for (int i=1; i<=m; i++){
    cin>>b[i];
}
if (n>m) {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (b[j]==a[i]) {
                max++;
                c[k]=b[j];
                k++;
            }
        }
    }
}
else {
   for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            if (b[j]==a[i]) {
                max++;
                c[k]=b[j];
                k++;
            }
        }
    }

}
cout<<max<<"\n";
for (int i=1; i<=k-1; i++){
    cout<<c[i];
}
return 0;
}
