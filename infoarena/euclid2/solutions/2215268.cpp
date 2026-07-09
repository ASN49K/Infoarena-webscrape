#include <iostream>
#include <fstream>

using namespace std;

int t,a,b;

int euclid(int a, int b){
    if(!b)  return a;
    return euclid(b,a%b);
}

int main()
{

    fstream f("euclid2.in",ios::in);
    fstream g("euclid2.out",ios::out);
    f>>t;
    while(t>0){
        f>>a>>b;
        g<<euclid(a,b)<<endl;
        t--;
    }

    f.close();
    g.close();

    return 0;
}


//    if(a==b){
//        return a;
//    }
//    else if(a>b){
//        if(a%b==0)
//            return b;
//        else
//            return euclid(a-b,b);
//    }
//    else if(b>a){
//        if(b%a==0)
//            return a;
//        else
//            return euclid(a,b-a);
//    }
