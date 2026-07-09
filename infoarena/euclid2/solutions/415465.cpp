#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    int a,b,r,n,i;
    ifstream f("euclid2.in");
    ofstream f1("euclid2.out");
    f>>n;
    for(i=1;i<=n;i++){
                      f>>a>>b;
                      while(a!=b){
                                  if(a>b) a=a-b;
                                  else b=b-a;
                                  }
                      
                      f1<<a<<endl;
                      }
                      f.close();
                      f1.close();
    system("PAUSE");
    return EXIT_SUCCESS;
}
