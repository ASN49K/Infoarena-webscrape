#include <fstream>

using namespace std;

int r;
int euclid(int a, int b){
         while(b!=0){r=a%b;a=b;b=r;};
         return a;
    };

int main(int argc, char *argv[]){

      int a,b,r, n, i;
          ifstream fin("euclid2.in");
          ofstream fout("euclid2.out");
      int T;
      fin >> T;

      for(i=1;i<=T;i++){
              fin>>a>>b;//citeste date
              euclid(a,b);
              fout<<a<<"\n";//scrie date
              }


      fin.close();
      fout.close();
  }
