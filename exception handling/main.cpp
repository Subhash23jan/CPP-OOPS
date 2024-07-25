// program to divide two numbers
// throws an exception when the divisor is 0

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {

    double numerator, denominator, divide;

    cout << "Enter numerator: ";
    cin >> numerator;

    cout << "Enter denominator: ";
    cin >> denominator;

    try {

        // throw an exception if denominator is 0
        if (denominator == 0)
            throw runtime_error;

        // not executed if denominator is 0
        divide = numerator / denominator;
        cout << numerator << " / " << denominator << " = " << divide << endl;
    } 

    catch (runtime_error &e) {
        cout << e.what() << endl;
    }

    return 0;
}