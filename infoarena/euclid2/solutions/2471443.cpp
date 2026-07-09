#include <iostream>
#include <fstream>
using namespace std;
ifstream f ("ex.in");
ofstream g ("ex.out");
int main()
{

    int x,y,c,n;
    f>>n;
    for(int i=0;i<n;i++){
        f>>x;
        f>>y;
        while(x !=y){
            if(x>y){
                x=x-y;
            }
            else{
                y=y-x;
            }

        }
        g<<x<<endl;
    }


    return 0;
}
