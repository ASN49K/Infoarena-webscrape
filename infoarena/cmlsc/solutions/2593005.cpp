#include <fstream>
#include <algorithm> // max
std::ifstream in ("cmlsc.in"); std::ofstream out ("cmlsc.out");


int main(){

    int A[1024], B[1024], AB[1024][1024], m, n;
    int Smax[1024];
    in>>n>>m;

    for(int i{1}; i<=n; ++i){
        in>>A[i];
    } 
    for(int i{1}; i<=m; ++i){
        in>>B[i];
    } 

    for(int i{1}; i<=n; ++i){
        for(int j{1}; j<=m; ++j){
            if(A[i]==B[j]){
                AB[i][j]=AB[i-1][j-1] + 1;
            }
            else{
                AB[i][j]=std::max(AB[i-1][j], AB[i][j-1]);
            }
        }
    }

    //solutia
    int k{0};
    int j=m;
    for(int i{n};i>=1;){
        if(A[i]==B[j]){
            Smax[++k]=A[i];
            --i;
            --j;
        }
        else if (AB[i-1][j] > AB[i][j-1]) --i;
        else --j;
    }

    out<<k<<'\n';
    for(int i{k}; i>=1; --i){
        out<<Smax[i]<<" ";
    }
    
}