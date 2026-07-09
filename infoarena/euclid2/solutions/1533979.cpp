#include <fstream>

using namespace std;

int main()
{
    int a,b,T,i;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>T;
    for(i=0;i<T;i++){
        f>>a;
        f>>b;
        //cod scaderi
        while(a != b){
            if(a > b){
                a = a-b;
            }else{
                b = b-a;
            }
        }

        g<<a<<endl;
    }
}
