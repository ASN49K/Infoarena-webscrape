#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int n,x,y,aux;
    f>>n;
    for(int i=0;i<n;i++){
        f>>x;
        f>>y;
        while(x>0&&y>0){
            if(x>y){
                aux=y;
                y=x%y;
                x=aux;
            }else{
                aux=x;
                x=y%x;
                y=aux;
            }
        }
        if(x>y) g<<x<<endl;
            else g<<y<<endl;
    }

    return 0;
}
