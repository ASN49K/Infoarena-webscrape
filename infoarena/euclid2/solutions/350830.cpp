#include<fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int t;
int cmmdc(int a,int b){
    int r;
    while(b != 0){
            r = a%b;
            a= b;
            b = r;
    }
return a;
}
int main(){
int i,x,y;
fin>>t;
for(i = 1; i <= t; i++){
      fin>>x>>y;
      fout<<cmmdc(x,y)<<"\n";
}
fin.close();
fout.close();
return 0;
}
