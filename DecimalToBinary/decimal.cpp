//We want to convert 1111011 to decimal

//1111011 -> 123

//If 0 return 0
//For each digit in the binary
//Multiply it by i^2
//add all numbers to answer

#include "../header.hpp"
using namespace std;

int binaryToDecimal (int num){
    if(num == 0){ //if 0 then return 0
        return 0;
    }

    int answer = 0; //We store the answer here
    int count = 0; // We count the current digit we are using
    int temp = num; // The current number we are iterating on starting with num

    while (temp > 0){ //While temp is greater than zero we loop over each digit
        int digit = temp % 10; //We get the right most digit and store it in digit
        temp /= 10; //We remove the right most digit
        answer += digit << count; //Using bit shift we use the current digit and count to convert that binary to decimal

        count++; //Increasing the count to move to the next binary position
    }
    return answer;
}

int main(){
    int binaryNum = 1111011;
    int decimalNum = binaryToDecimal(binaryNum);
    cout << decimalNum << endl;
}