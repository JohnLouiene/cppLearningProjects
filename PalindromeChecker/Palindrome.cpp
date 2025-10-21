#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(int x) {
    vector<int> digits;
    if(x < 0){
        return false;
    }
    if (x == 0){
        return true;
    }
    while(x > 0) {
        digits.push_back(x % 10);
        x /= 10;
    }

    for (int i = 0, j = digits.size() - 1; i < j; i++, j--) {
        if(digits[i] != digits[j]) {
            return false;
        }
    }
    return true;
}

int main() {
    int numbers = 0;
    cout << isPalindrome(numbers) << endl;
    return 0;
}
