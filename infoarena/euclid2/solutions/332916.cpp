#include <fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(int a, int b){
int c;
while (b) {
      c = a % b;  
      a = b;  
      b = c;  
      } 
    return a;
}
    
int main(){
    int a, b, c;
    in>>a;
    for(a; a>0; a--){
           in>>b>>c;
           out<<cmmdc(b,c)<<"\n";
           }
    in.close();
    out.close();
    return 0;
    }
