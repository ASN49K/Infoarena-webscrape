#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;
int A,B,n,i;

int euclid(int a, int b){
      if(!b) return a;
    return  euclid(b, a%b);
} 

int main(void)
{
    
    ifstream f("euclid2.in");
    ofstream f1("euclid2.out");
    f>>n;
    for(i=1;i<=n;i++){
                      f>>A>>B;
                     f1<<euclid(A,B)<<endl;
                    }
                      f.close();
                      f1.close();
    system("PAUSE");
    return EXIT_SUCCESS;
}
