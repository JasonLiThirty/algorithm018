#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

//two pointers(basic) O(n)
// int removeDuplicates(vector<int>& nums) {
//     if(nums.empty()) { return 0; }
//     int i = 0;
//     for(int j = 1; j < (int)nums.size();) {
//         if(nums[i] == nums[j]) { j++; }
//         else {
//             if (j == i + 1) { i++; j++; }
//             else {
//                 nums[++i] = nums[j++]; 
//             }
//         }
//     }
//     nums.resize(i + 1);
//     return nums.size();
// }

//two pointers(optimazing) O(n)
// int removeDuplicates(vector<int>& nums) {
//     if(nums.empty()) { return 0; }
//     int i = 0;
//     for(int j = 1; j < (int)nums.size(); j++) {
//         if (nums[i] != nums[j]) {
//             i = i + 1;
//             if(i != j) { nums[i] = nums[j]; }
//         }
//     }
//     nums.resize(i + 1);
//     return nums.size();
// }

//fast and slow pointer: Only focus on diff O(n)
// int removeDuplicates(vector<int>& nums) {
//     if(nums.empty()) { return 0; }
//     int i = 0;
//     for(int j = 0; j < (int)nums.size() - 1; j++) {
//         if (nums[j] != nums[j+1]) {
//             nums[++i] = nums[j+1];
//         }
//     }
//     nums.resize(i + 1);
//     return nums.size();
// }

//slow pointer and "range-based" loops O(n)
// int removeDuplicates(vector<int>& nums) {
//     if(nums.empty()) { return 0; }
//     int i = 0;
//     for (int &n : nums) {
//         if (!i || n > nums[i - 1]) {
//             if (nums[i] != n) { nums[i] = n;}
//             i++;
//         }
//     }
//     nums.resize(i);
//     return nums.size();
// }

//number of calculation intervals O(n)
// int removeDuplicates(vector<int>& nums) {
//     if(nums.empty()) { return 0; }
//     int repeated = 0;
//     for (int i = 1; i < (int)nums.size(); i++) {
//         if (nums[i] != nums[i - 1]) {
//             if (repeated) { nums[i - repeated] = nums[i]; }
//         }
//         else { repeated++; }
//     }
//     nums.resize((int)nums.size() - repeated);
//     return nums.size();
// }

//stl
int removeDuplicates(vector<int>& nums) {
    if(nums.empty()) { return 0; }
    nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
    return nums.size();
}

int main() {

    // int nums[] = {1,2};
    // std::vector<int> array(nums, nums + 2);
  
    // int nums[] = {1,1,2};
    // std::vector<int> array(nums, nums + 3);


    int nums[] = {0,0,1,1,1,2,2,3,3,4};
    std::vector<int> array(nums, nums + 10);
    
    std::cout << removeDuplicates(array) << std::endl;


    //print
    std::cout << "[";
    for (int i = 0; i < (int)array.size(); i++) {
        std::cout << array[i];
        if (i != (int)array.size() - 1) {
            std::cout << ","; 
        }   
    }
    std::cout << "]" <<std::endl;
    return 0;
}