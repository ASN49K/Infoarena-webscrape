#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
/*ifstream in("sclm.in");
ofstream out("sclm.out");
int main(){
    int n,A[1001],i,j,L[1001],Next[1001],pmax=1;
    in>>n;
    for(i=1;i<=n;++i){
        in>>A[i];
    }
//construiesc L[] si Next[], astfel cel mai mare elem. al L[] este lung. subsirului si Next[i]->next element from s.c.m. which starts with the element A[i].
L[n] = 1, Next[n] = -1;
for(i = n-1 ; i >= 1 ;--i)
{
    L[i] = 1 , Next[n] = -1;
    for(j = i + 1 ; j <= n; ++ j){
        if(A[i] <= A[j] && L[i] < (L[j] + 1)){
            L[i] = L[j] + 1;
            Next[i] = j;
        }
    }
}
//det. cel mai > indice
for(i=2;i<=n;++i){
    if(L[i]>L[pmax]){
        pmax=i;
    }
}
out<<L[pmax]<<'\n';
// afisez subsirul
while(pmax!=Next[pmax])
{
    out << pmax << " ";
    pmax = Next[pmax];
}
    return 0;
}
*/

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int C[1010][1010];
int lsubsir(char a[1001],char b[1001],int la, int lb){
    int i,j;
    for(i=0;i<=la;++i){
        C[i][0]=0;
    }
    for(j=0;j<=lb;++j){
        C[0][j]=0;
    }
    for(i=1;i<=la;++i){
        for(j=1;j<=lb;++j){
            if(a[i]==b[j]){
                C[i][j]=C[i-1][j-1]+1;
            }
            else{
                C[i][j]=max(C[i][j-1],C[i-1][j]);
            }
        }
    }
    return C[la][lb];
}

int main(){
    char sir1[1001],sir2[1001];
    in.getline(sir1,1001);
    in.getline(sir2,1001);
    int lsir1=strlen(sir1),lsir2=strlen(sir2);
    out<<lsubsir(sir1,sir2,lsir1,lsir2);
    return 0;
}