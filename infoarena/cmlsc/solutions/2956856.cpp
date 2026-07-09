#include <fstream>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int mat[1100][1100];
int sir[1100];
int A[1100];
int B[1100];
int main(){
     int a,b;
     cin >> a >> b;
     for(int i = 1; i <= a; i++){
         cin >> A[i];
     } 
     for(int i = 1; i <= b; i++){
     	cin >> B[i];
     }
     for(int i = 1; i <= a; i++){
     	for(int j = 1; j <= b; j++){
     		if(A[i] == B[i]){
     			mat[i][j] = mat[i-1][j-1] + 1;
     		}else{
     			mat[i][j] = max(mat[i-1][j],mat[i][j-1]);
     		}
     	}
     }
     int i = a;
     int j = b;
     int cnt = 0;
     while(i && j){
     	if(A[i]==B[j]){
           cnt++;
        sir[cnt] = A[i]; 
        i--;
        j--;
           }else if(mat[i-1][j]<mat[i][j-1]){
           	j--;
           }else{
           	   i--;
           }
     }
   cout << mat[a][b];
   for(int i = cnt; i>=1; i--){
   	   cout << sir[i] << " ";
   }


	return 0;
}