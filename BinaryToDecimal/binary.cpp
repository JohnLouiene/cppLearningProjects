//We want to convert 1234 into binary
// 0 + 0 = 1
// 1 + 0 = 1
// 1 + 1 = 10

//If the number is 0 we return 0

/*Conversion steps:
Divide the number by 2.
Get the integer quotient for the next iteration.
Get the remainder for the binary digit.
Repeat the steps until the quotient is equal to 0.
*/


#include "../header.hpp"
using namespace std;

class BinaryConverter{
private:
    string binaryToDecimal(int num){
    if (num == 0){
        return "0";
    }

    string answer;
    while (num > 0){
        int modulo = num % 2;
        answer = to_string(modulo) + answer;
        num /= 2;
    }

    return answer;
}
public:
    void showAnswer(int num){
        cout << "The answer is " << binaryToDecimal(num) << endl; 
    }
};

int main(){
    BinaryConverter converter;
    converter.showAnswer(123);
    
    
    return 0;
}

