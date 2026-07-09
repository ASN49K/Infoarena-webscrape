//
//  main.cpp
//  Euclid
//
//  Created by Olaru Gabriel on 09/04/2018.
//  Copyright © 2018 Olaru Gabriel. All rights reserved.
//

//#include <stdio.h>
//
//#define miin(a,b) ((a < b) ? a : b)
//
//int T, A, B;
//
//int main(int argc, const char * argv[]) {
//
//    int i;
//    freopen("/Users/olarugabriel/Documents/XCode/Euclid/euclid2.in", "r", stdin);
//    freopen("/Users/olarugabriel/Documents/XCode/Euclid/euclid2.out", "w", stdout);
//
//    for(scanf("%d", &T);  T; --T)
//    {
//        scanf("%d %d", &A, &B);
//
//        for(i = miin(A,B); i; --i)
//        {
//            if(A % i == 0 && B % i == 0)
//            {
//                printf("%d\n", i);
//                break;
//            }
//        }
//    }
//    return 0;
//}

int T, A,B;

#include <stdio.h>

int gcd(int a, int b)
{
    if(!b)
        return a;
    
    return gcd(b, a % b);
}

int main(int argc, const char * argv[]){
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    
    for(scanf("%d", &T);  T; --T)
    {
        scanf("%d %d", &A, &B);
        
        printf("%d\n", gcd(A, B));
    }
    
    return 0;
}
