#include <iostream>
#include <time.h>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

vector<int> nums = {-7, -4, -1, 2, -4, 3, 5, 5, 7, -9};
vector<tuple<int, int, int>> result;

int main(){
    sort(nums.begin(), nums.end());
    
    for (int begginPointer = 0; begginPointer < nums.size() - 2; begginPointer++) {
        
        if (begginPointer > 0 && nums[begginPointer] == nums[begginPointer - 1])
            continue;

        int midPointer = begginPointer + 1;
        int endPointer = nums.size() - 1;

        while (midPointer < endPointer) {
            int sum = nums[begginPointer] + nums[midPointer] + nums[endPointer];
            if (sum == 0) {
                result.push_back(make_tuple(nums[begginPointer], nums[midPointer], nums[endPointer]));

                // Evitar duplicatas
                while (midPointer < endPointer && nums[midPointer] == nums[midPointer + 1]) ++midPointer;
                while (midPointer < endPointer && nums[endPointer] == nums[endPointer - 1]) --endPointer;

                ++midPointer;
                --endPointer;
                
            } else if (sum < 0) {
                ++midPointer;
            } else {
                --endPointer;
            }
        }
    }

    for (const auto& item : result)
        cout << get<0>(item) << " " << get<1>(item) << " " << get<2>(item) << endl;

}