#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

vector<int> twosum(vector<int>& nums, int target){
    unordered_map<int, int> indexToValue; 
    for(int i = 0; i < nums.size(); i++){
        int compliment = target - nums[i]; //Find the compliment of the target number and the current number
        if(indexToValue.find(compliment) != indexToValue.end()){ //Check if the compliment exists in the map
            return{indexToValue[compliment], i}; //If found add the compliment index and the current index to the return value
        }
        indexToValue[nums[i]] = i; //Otherwise store the value and assign the index of that value to the map
    }
    return {};
}

int main(){
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int>answer = twosum(nums, target);
    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << endl;
    }
    return 0;
}