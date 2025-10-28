#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int romanToInt(string x){
    int sum = 0;

    map<char, int> rom = {{'I', 1}, {'V', 5}, {'X', 10}, 
    {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}}; // Mapping the roman numerals

    for (int i = 0; i < x.length(); i++){
        int value = rom[x[i]]; //The current value of the current numeral
        if((i + 1) < x.length()){ //Looking up if we can look up the next value of the array
            int value2 = rom[x[i +1]]; //The value of the next numeral
            if (value < value2){ //Subtracting if the current numeral is smaller than the next one
                sum -= value;
            }
            else{ //Adding if the current numeral is bigger than the next one
                sum += value;
            }
        }
        else{ //If we are at the last numeral we just add it
            sum += value;
        }
    }
    return sum;
}


int main(){
    string x = "CXIV";
    int num = romanToInt(x);
    cout << num << endl;
    return 0;
}