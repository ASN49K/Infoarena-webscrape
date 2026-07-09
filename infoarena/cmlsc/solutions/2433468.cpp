#include <iostream>
#include <fstream>

#define MIN(M,N) ((M)<(N)?(M):(N))
#define MAX(a,b) ((a)>(b)?(a):(b))

using namespace std;

ifstream f("cmlsc.in");
ofstream o("cmlsc.out");

int M,N,A[1024],C[1024],B[1024];

void rez(){

    f>>M>>N;

    int min=256,max=-1,MAX=0;

    for(int i=0;i<M;i++){
        f>>A[i];

        C[A[i]]++;

        min=MIN(min,A[i]);
        max=MAX(max,A[i]);
    }
    for(int i=0;i<N;i++){
        f>>B[i];

        C[B[i]]++; if(C[B[i]]==2) MAX++;

        min=MIN(min,B[i]);
        max=MAX(max,B[i]);
    }
    o<<MAX<<endl;
    for(int i=min;i<=max;i++)
        if(C[i]==2) o<<i<<" ";

}

int main()
{
    rez();
    return 0;
}
