#include <iostream>
#include <fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

// int main(){
//     int n,a,b,i,j,sol;
//     in>>n;
//     for(i=0;i<n;++i){
//         in>>a>>b;
//         sol=1;
//         for(j=min(a,b);j>=1;--j){
//             if(a%j==0&&b%j==0){
//                 out<<j<<endl;
//                 break;
//             }
//         }
//     }
    
//     return 0;
// }

int main(){
    int n,a,b,i;
    in>>n;
    for(i=0;i<n;++i){
        in>>a>>b;
        while(a!=b){
            if(a>b){
                a-=b;
            }
            else{
                b-=a;
        }
    }
    out<<a<<endl;
    }

    return 0;
}