#include <fstream>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int A[1100],B[1100];
int a,b;
int mat[1100][1100];
int sir[1100];
int main(){
    int c = 0;
    cin >> a >> b;
    for(int i = 1; i <= a; i++){
      cin >> A[i];
   }
    for(int i = 1; i <= b; i++){
      cin >> B[i];
    }
    for(int i = 1; i <= a; i++){
      for(int j = 1; j <= b; j++){
         if(A[i]==B[j]){
            mat[i][j] = mat[i-1][j-1]+1;
         }else{
            mat[i][j] = max(mat[i-1][j],mat[i][j-1]);
         }
      }
    }
    int i = a;
    int j = b;
    while(i and j){
      if(A[i]==B[j]){
         c++;
         sir[c] = A[i];
         i--;
         j--;
      }else if(mat[i-1][j]<mat[i][j-1]){
         j--;
      }else{
         i--;
      }
    }
    cout << mat[a][b] << endl;
    for(int i = c; i >= 1; i--){
      cout << sir[i] <<  " ";
    }
   return 0;
}