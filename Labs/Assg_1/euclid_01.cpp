// Code Euclids Algorithms

#include <iostream>

int euclidGCD(int m, int n)
{
    while (n != 0)
    {
        int remainder = m % n;
        m = n;
        n = remainder;
    }
    return m;
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

    int result = euclidGCD(m, n);

    std::cout<< "GCD(" << m << ", " << n << ") = "
            << result << "\n";
    
    return 0;
}
