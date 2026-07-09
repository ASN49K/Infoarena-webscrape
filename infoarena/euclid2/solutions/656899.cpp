#include<fstream>
using namespace std;

int cmmdc(int a,int b){
    int k;
  while(a%b!=0){   
    k=b;
    b=a%b;
    a=k;               
    }    
    return b;        
} 

int main(void){
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int a,b,t;
    fin>>t;
    while(t--){
          fin>>a>>b;
          if(a>b)fout<<cmmdc(a,b)<<'\n';
            else fout<<cmmdc(b,a)<<'\n';
            }     
 return 0;   
}
