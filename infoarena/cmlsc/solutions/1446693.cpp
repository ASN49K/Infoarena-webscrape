#include <iostream>
#include <fstream>
using namespace std;
int m,n;
int A[256],B[256],C[256];
int main()
{  ifstream FILE;
    FILE.open("cmlsc.in");


    FILE>> m >>n;
    for(int i=0;i<m;i++)
    FILE>>A[i];
    for(int i=0;i<n;i++)
    FILE>>B[i];
    int k=0;
     int N=0;
     int v=0;
      for(int i=0;i<m;i++)
      for(int j=k;j<n;j++){
       if (A[i]==B[j]){
        N++;
        C[v]=A[i];
        v++;
        k=j;
        break;
       }

      }
ofstream FILE1;
FILE1.open("cmlsc.out");

    FILE1 << v << endl;
    for(int i=0; i<v;i++)
        FILE1<<C[i]<<" ";
    return 0;
}
