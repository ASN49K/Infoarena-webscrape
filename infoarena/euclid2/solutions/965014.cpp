#include<fstream>

int main()
{

    int a,b,i,r,aux;
    std::ifstream in("euclid2.in");
    std::ofstream out("euclid2.out");
    in>>i;
    for( int j = 0 ; j < i ; j++)
    {

        in>>a>>b;
        if(b > a)
        {

            a = aux;
            a = b;
            b = aux;
        }
        r = a % b;
        while( r != 0)
        {

            a = b;
            b = r;
            r = a % b;
        }
        out<<b;
    }
    in.close();
    out.close();
    return 0;
}
