#include <iostream>
#include <string>

// 1 = 1 grimy
// 1+2= 3 grimy
// 1+2+3=6 black
// 1+2+3+4=10 black
// 1+2+...+5 = 15 grimy
// 1+..+6 = 21 grimy
// 1+..+7 = 28 black.


//1+2+3+4+5=15
//1+2+3+4-5=5
//1+2+3-4+5=7
//1+2+3-4-5=-3
//1+2-3+4+5=9
//1+2-3+4-5=-1
//1+2-3-4+5=1
//1+2-3-4-5=-9
//1-2+3+4+5=11
//1-2+3+4-5=1
//1-2+3-4+5=3
//1-2+3-4-5=-7
//1-2-3+4+5=5
//1-2-3+4-5=-5
//1-2-3-4+5=-3
//1-2-3-4-5=-13

//The change in the operation type does not affect the parity of the result.
//sum and difference of even numbers is an even number: 4-2=2; 4+2=6
//sum and diff of odd number is an even number: 3-1 = 2 ; 3+1 = 4
//Therefore, to evaluate the result of the game, we consider the sum of the arithmetic progression

std::string estimate(const uint32_t n)
{
    std::string out;
    switch(n % 4){
        case 0 :
        case 3 :    // n+1 (mod4 ) == 0 eq n(mod 4) == 3
            out = "black";
            break;
        
        default:
            out = "grimy";
    }

    return std::move(out);
}

int main()
{
   uint32_t n;
   std::cin >> n;

   //uint32_t ar_pr_sum = ((1+n)*n)/2;
   //std::cout << ((ar_pr_sum % 2 == 0) ? "black" : "grimy") << std::endl;

    ////ar_pr_sum is even number is only if n+1(mod 4) == 0  or n(mod 4) == 0

    std::cout << estimate(n) << std::endl;


    return 0;
}
