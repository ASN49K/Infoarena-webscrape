#include <iostream>
#include <fstream>
#define MaxL 1024
#define loop(x,n) for(int x = 1; x <= n; ++x)
#define maxim(a, b) ((a > b) ? a : b)
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a,b,A[MaxL],B[MaxL],D[MaxL][MaxL], sir[MaxL];
int main() {
  fin>>a>>b;
  loop(i, a){
    fin>>A[i];
  }
  loop(j, b){
    fin>>B[j];
  }

  loop(i, a){
    loop(j, b){
      if(A[i]==B[j]){
        D[i][j]=1+D[i-1][j-1];
      }else{
        D[i][j]=maxim(D[i-1][j],D[i][j-1]);
      }
    }
  }

  cout << "  ";
  loop(j, b){
    cout << B[j] <<" ";
  }
  cout << endl;
  loop(i, a){
    cout << A[i] <<" ";
    loop(j, b){
      cout << D[i][j] << " ";
    }
    cout << endl;
  }

  int x = 0;
  int maxlength = 0;
  loop(i, a){
    loop(j, b){
      if(D[i][j]>x){
        sir[++maxlength]=A[i];
        x=D[i][j];
      }
    }
  }
  fout<<maxlength<<endl;
  loop(i, maxlength){
    fout<<sir[i]<<" ";
  }
  cout << "Hello World!\n";
}