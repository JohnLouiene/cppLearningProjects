#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

/* I want to write a program that will allow me to enter many numbers, 
then calculates the average.*/
class Calculator {
public:
    int Calculate(vector<int> numbers) {
        int sum = 0;
        for (int num : numbers) {
            sum += num;
        }
        sum /= numbers.size();
        cout << "The average is: " << sum << endl;
        return sum;
    }
};

int main() {
    cout << "enter the amount of numbers to insert :";
    vector<int> numbers;
    int input = 0;
    cin >> input;
    cout << endl;
    
    for (int i = 0; i < input; i++){
        int number;
        cout << "Enter number" << i + 1 << ": ";
        cin >> number;
        cout << endl;
        numbers.push_back(number);
    }

    Calculator calc;
    calc.Calculate(numbers);
    return 0;
}