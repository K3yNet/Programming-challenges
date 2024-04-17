#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int target = 7;
vector<int> nums = {2, 7, 11, 5, 8, 15, 3, 33, 125};
unordered_map<int, int> hasher;

int resultX, resultY;

int main(){
    for (unsigned i = 0; i < nums.size(); i++) {
        if (hasher.find(nums[i]) != hasher.end()) {
            resultX = hasher[nums[i]];
            resultY = i;
        }
        hasher[target - nums[i]] = i;
    }
    cout << resultX << " " << resultY << endl;
}