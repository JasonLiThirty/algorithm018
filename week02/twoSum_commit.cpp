//https://leetcode-cn.com/problems/two-sum/ 

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


//1.暴力枚举-双循环，时间复杂度高(O(n^2))
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         for(int i = 0; i < nums.size() - 1; i++) {
//             for(int j = i + 1; j < nums.size(); j++) {
//                 if (nums[i] + nums[j] == target) {
//                     return {i, j};
//                 }
//             }
//         }
//         return {};
//     }
// };

//2.使用map保存以前遍历结果-时间复杂度为(O(n))-推荐
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> traversedMap;
        for (int i = 0; i < (int)nums.size(); i++) {
            auto it = traversedMap.find(target - nums[i]);
            if (it != traversedMap.end()) {
                return {it->second, i};
            }
            traversedMap[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    int nums[] = {2,7,11,15};
    std::vector<int> array(nums, nums + 4);
    int target = 9;

    Solution solution;
    vector<int> result = solution.twoSum(array, target);

    //print
    std::cout << "[";
    for (int i = 0; i < (int)result.size(); i++) {
        std::cout << result[i];
        if (i != (int)result.size() - 1) {
            std::cout << ","; 
        }   
    }
    std::cout << "]" <<std::endl;

    return 0;
}