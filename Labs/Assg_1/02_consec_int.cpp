// Consecutive integers Ckecking Algorithm

#include <iostream>
#include <algorithm>

int conseutiveIntGCD(int m, int n)
{
    int  t = std::min(m,n);

    while (t >0){
        if (m % t == 0){
            if (n % t ==0){
                return t;
            }
        }
        t--;
    }
    return 1;
}

int main(){
    int m;
    int n;

    std::cout<< "Enter the first psotive num: ";
    std::cin >> m;

    std::cout<< "Enter de second positive mun:";
    std::cin>> n;

    if (m <= 0 || n <= 0){
        std::cout<< "Both numbers must be positive.\n";
        return 1;
    }

    int result = conseutiveIntGCD(m, n);

    std::cout<< "GCD(" << m << ", " << n << ") = "
            << result << "\n";
    
    return 0;
}