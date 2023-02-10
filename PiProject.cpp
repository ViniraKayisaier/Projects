#include<cmath>
#include<iostream>
#include<stdio.h>

using namespace std;

double actual_PI = 3.14159265358973;

double PI(int iteration){
    int k = 0;
    double value=0;

    for(k=0; k<=iteration; k++){
        value += -1/(double)(2*k+1);
        value *= -1;
    }
    return value;
}

int main(){
    int iteration_number;
    cout << "Please enter a non-negative integer upper limit of summation for the Leibnitz formula for computing pi: ";
    cin >> iteration_number;
    cout << " PI (approx): " <<  abs(PI(iteration_number)) * 4 << "; n: " << iteration_number << endl;
    cout << " PI (actual): " <<  actual_PI<<endl;

return 0;
}
