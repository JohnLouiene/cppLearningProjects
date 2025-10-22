#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
using namespace std;

int main(){
    vector<int> nums = {6, 3, 2, 8};
    map<int, int> test;
    for(int i = 0; i < nums.size(); i++){
        test[nums[i]] = i;
    }
    for(auto &p : test){
        cout << p.first << " and " << p.second << endl;
    }

    auto testing = test.find(2);
    if(testing != test.end()){
        int value = testing->second;
        cout << value << endl;
    }
}