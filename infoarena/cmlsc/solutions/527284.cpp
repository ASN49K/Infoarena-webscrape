#include <fstream>
using namespace std;

int main(){
    ifstream f("date.in");
    ofstream g("date.out");
    
    int M,N,i,A[256],B[256];
    f>>M>>N;
    
    for(i=1; i<=M; i++)
    f>>A[i];
    for(i=1; i<=N; i++)
    f>>B[i];
    
    for(i=1; i<=M; i++)
    g<<A[i];
    g<<"\n";
    for(i=1; i<=N; i++)
    g<<B[i];
    
    f.close(); g.close();
    return 0;
}
    
    
