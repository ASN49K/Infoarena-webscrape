#include <fstream>
#include <algorithm> // max
std::ifstream in ("cmlsc.in"); std::ofstream out ("cmlsc.out");


int main(){

    int A[1024], B[1024], AB[1024][1024], m, n;
    int Smax[1024];
    in>>m>>n;

    for(auto i{1}; i<=m; ++i){
        in>>A[i];
    } 
    for(auto i{1}; i<=n; ++i){
        in>>B[i];
    } 

    for(auto i{1}; i<=m; ++i){
        for(auto j{1}; j<=n; ++j){
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
    int j=n;
    for(int i{m};i>=1;){
        if(A[i]==B[j]){
            Smax[++k]=A[i];
            --j;
            --i;
        }
        else if (AB[i-1][j] > AB[i][j-1]) --i;
        else --j;
    }

    out<<k<<'\n';
    for(auto i{k}; i>=1; --i){
        out<<Smax[i]<<" ";
    }
    
}