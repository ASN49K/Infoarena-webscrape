# include <iostream>
# include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int euclid(int a, int b){

 if (a > b){
  a=a+b;
  b=a-b;
  a=a-b;
 }

 int r;

 while (b % a!=0){
  r = b % a;
  b = a;
  a = r;
 }

 return a;

};

int sol(){
 int a,b;
 f>>a>>b;
 return euclid(a,b);
};

main(){
 int n,a,b;
 f>> n;
 for (int i = 0; i < n; i++){
  g<< sol() <<'\n';
 }
}
