#include<fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int N , M;
int V1[1025] , V2[1025] , Dp[1025][1025];

void Rec(int indx1 , int indx2){
     if(indx1!=0 && indx2!=0){
         if(V1[indx1] == V2[indx2]){
             Rec(indx1-1,indx2-1);
             fout<<V1[indx1]<<' ';
         }
         else{
             if(Dp[indx1-1][indx2] > Dp[indx1][indx2-1])
                   Rec(indx1-1,indx2);
             else
                   Rec(indx1,indx2-1);
         }
     }
 }

int main()
{
fin>>N>>M;
for(int i=1 ; i<=N ; i++)
    fin>>V1[i];

for(int i=1 ; i<=M ; i++)
    fin>>V2[i];

for(int i=1 ; i<=N ; i++)
   for(int j=1 ; j<=M ; j++){
        if(V1[i] == V2[j]){
            Dp[i][j]=1+Dp[i-1][j-1];
        }
        else Dp[i][j]=max(Dp[i-1][j],Dp[i][j-1]);
   }

fout<<Dp[N][M]<<'\n';
Rec(N,M);
return 0;
}
