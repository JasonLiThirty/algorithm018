#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//enumerate O(n^2)
vector<int> twoSum(vector<int>& nums, int target) {
    for (int i = 0; i < (int)nums.size(); i++) {
        for (int j = i+1; j < (int)nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                return{i, j};
            }
        }
    }
    return {};
}

//using map O(n)
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


int main()
{
    int nums[] = {2,7,11,15};
    std::vector<int> array(nums, nums+4);
    int target = 9;

    vector<int> result = twoSum(array, target);

    //print
    std::cout << "{" ;
    for(int i = 0; i < (int)result.size(); i++) {
        std::cout << result[i];
        if (i != (int)result.size() - 1){
            std::cout << ","; 
        }   
    }
    std::cout << "}" <<std::endl;

    return 0;
}