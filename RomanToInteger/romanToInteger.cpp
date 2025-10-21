#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int romanToInt(string x){
    int sum = 0;
    vector<string> numerals; //Initializing an array to store

    map<string, int> rom = {{"I", 1}, {"V", 5}, {"X", 10}, 
    {"L", 50}, {"C", 100}, {"D", 500}, {"M", 1000}}; // Mapping the roman numerals

    for (char c : x){
        numerals.push_back(string(1, c));
    } //Storing each numeral for x into the array
    
    for (int i = 0; i < numerals.size(); i++){
        string s = numerals[i]; //The current numeral
        int value = rom[s]; //The current value of the current numeral
        if((i + 1) < numerals.size()){ //Looking up if we can look up the next value of the array
            string t = numerals[i + 1]; //The numeral next to our current value
            int value2 = rom[t]; //The value of the next numeral
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