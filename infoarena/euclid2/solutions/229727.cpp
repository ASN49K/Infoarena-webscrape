#include <fstream>

using namespace std;

int a ,b ,i ,T ;
int euclid(int a, int b){
         int r;
         while(b!=0){r=a%b;a=b;b=r;};
         return a;
    };

int main(int argc, char *argv[]){


          ifstream fin("euclid2.in");
          ofstream fout("euclid2.out");

      fin >> T;
      for(i=1;i<=T;i++){
              fin>>a>>b;//citeste date
              fout<<euclid(a,b)<<"\n";//scrie date
              }


      fin.close();
      fout.close();
  }
