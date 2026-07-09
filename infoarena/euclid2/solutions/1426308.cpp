#include <iostream>

void swapNumbers(int& a, int &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}


int cmmdc(int a, int b)
{
    /*set a as largest element*/
    if(a < b)
    {
        swapNumbers(a,b);
    }

    while(a != 0)
    {
        if(a % b == 0)
        {
            return b;
        }
        else
        {
            int r = a % b;
            a = b;
            b = r;
        }
    }
}


int main()
{
    int a, b;
    while(1)
    {
        std::cin >> a >> b;
        std::cout << "Cmmdc = " << cmmdc(a,b) << "\n";
    }
}
