#include <iostream>
#include <limits>
using namespace std;

/*This program takes two numbers as input and 
performs addition, subtraction, multiplication, and division.*/

int Calculator(int a, int b, string c) {
    int ans = 0;
    if (c == "sum"){
        ans = a + b;
    }
    else if (c == "subtract"){
        ans = a - b;
    }
    else if (c == "divide"){
        ans = a / b;
    }
    else if (c == "multiply"){
        ans = a * b;
    }
    else{
        cout << "Unknown operation, try again" << endl;
    }
    cout << "The answer is: " << ans << endl;
    return ans;
}

int main() {
    while (true){
        int a = 0;
        int b = 0;
        string c = "";
        cout << "enter two numbers, then the operation: " << endl;
        if (!(cin >> a >> b >> c)){
            break;
        }
        if (c == "exit" || c == "quit" || c == "q") break;
        Calculator(a, b, c);
        cout << endl;
        cout << "Press ENTER to continue... " << endl;
        cin.ignore();
        cin.get();
    }
    cout << "Program Terminated" << endl;
    return 0;
}