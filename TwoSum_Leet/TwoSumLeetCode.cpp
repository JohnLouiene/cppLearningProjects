#include <iostream>
#include <vector>
using namespace std;

vector<int> twosum = {2,7,11,15};
int target = 9;

int main(){
    vector<int> twosum = {};
    int num1 = 0;
    int num2 = 0;
    for (int i = 0; i < twosum.size(); i++){
        for (int j = 1; j < twosum.size(); j++){
            int result = twosum[i] + twosum[j];
            if (target == result){
                num1 = twosum[i];
                num2 = twosum[j];
            }
        }
    }
    twosum.push_back(num1);
    twosum.push_back(num2);
    return 0;
}