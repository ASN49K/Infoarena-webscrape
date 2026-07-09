#include <iostream>
#include <fstream>

using namespace std;

ifstream in ("euclid.in");
ofstream out ("euclid.out");

int main()
{
    int T, A, B, Ans;

    for (in >> T; T; T --){
        in >> A >> B;

        __asm__
        (
            "movl %1, %%eax;"
            "movl %2, %%ebx;"
            "loop:"
            "test %%ebx, %%ebx;"
            "je done;"
            "xorl %%edx, %%edx;"
            "divl %%ebx;"
            "movl %%ebx, %%eax;"
            "movl %%edx, %%ebx;"
            "jmp loop;"
            "done:"
            "movl %%eax, %0;"
            : "=r" (Ans)
            : "r" (A), "r" (B)
            : "%eax", "%ebx", "%edx"
        );

        out << Ans << "\n";
    }

    return 0;
}
