#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool isValid(string s) {
    stack<char> parentheses; //Create a stack of each bracket

    for(char c: s){ //For each bracket we start with
        if(c == '(' || c == '{' || c == '['){ //If it is an open bracket we push to the top of the stack
            parentheses.push(c);
        }
        else if(c == ')' || c == '}' || c == ']'){ //If it is a closed bracket
            if(parentheses.empty()) return false; //If the stack is empty and we start with a closed bracket return false
            char top = parentheses.top(); //Otherwise check the current top of the stack
            if((c == ')' && top != '(') || 
               (c == '}' && top != '{') || 
               (c == ']' && top != '[')){ 
                return false; //If the current closed bracket does not match the open bracket at the top of the stack return false.
            }
            parentheses.pop(); //If it does match and it doesn't trigger the false conditions we pop the top of the stack. 
        }
    }
    return parentheses.empty(); //If the stack is empty that means we matched every bracket, if the stack has a remaining open bracket we return false
}

int main(){

    string s = "([(]))";
    bool test = isValid(s);
    if(test == 1){
        cout << "true" << endl;
    }
    else if(test == 0){
        cout << "false" << endl;
    }
    return 0; 
}