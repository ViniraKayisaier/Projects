#include <iostream>
#include <stdexcept>
#include <string>

unsigned long sigma(unsigned long n){
    unsigned long sum = 0;
    int k;

    try{
        if (n < 1){
            throw std::runtime_error("n must be greater than or equal to 1");
        }

        for (int i = 1; i <= n; i++){
            sum += i;
        }
        std::cout << "Sum: " << sum << std::endl;
            k = (n*(n+1) / 2);
            std::cout << "K: " << k << std::endl;

        if (k != sum){
            throw std::runtime_error("k must equal the sum");
        }
    }
    catch (std::runtime_error & ex){
        std::cout << "Exception: " << ex.what() << std::endl;
        sum = 0;
    }

    return sum;
}
    int main(){
        int sum = sigma(5);
        std::cout << "sigma(5) = " << sum << std::endl;

        return 0;
    }
