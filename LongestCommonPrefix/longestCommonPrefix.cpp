#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
        string output = "";
        if(strs.empty()){
            return output;
        }
        string base = strs[0];
        for(int i = 0; i < strs.size(); i++){
                if(strs[i].size() < base.size()){
                    base = strs[i];
                }
        }
        for(int i = 0; i < base.size(); i++){
            for(int j = 0; j < strs.size(); j++){
                if(base[i] != strs[j][i]){
                    return output;
                }
            }
            output += base[i];
        }
        return output;
}
    
int main(){
    vector<string> test = {"flower","flow","flight"};
    string output = longestCommonPrefix(test);
    cout << output << endl;
    return 0;
}