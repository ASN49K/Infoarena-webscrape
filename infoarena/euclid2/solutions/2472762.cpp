#include<fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int n, int k){

int i,mn;

if(n<k)mn=n;
else mn=k;

for(i=mn;i>=1;i--)if(n%i==0 && k%i==0)return i;

}

int main(){

int T,a[1000][2];

fin>>T;

for(int i=1; i<=T; i++)
    for(int j=1;j<=2;j++)
        fin>>a[i][j];
int j=1;
for(int i=1; i<=T; i++){
        fout<<cmmdc(a[i][j],a[i][j+1])<<"\n";
        j=1;
    }


}
