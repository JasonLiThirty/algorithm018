#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

// double loop with swap O(nlongn)
// void moveZeroes(vector<int>& nums) {
//     for (int i = 0; i < (int)nums.size() - 1; i++) {
//         if (nums[i] == 0) {
//             for(int j = i + 1; j < (int)nums.size(); j++) {
//                 if(nums[j] != 0) {
//                     swap(nums[i++], nums[j]);
//                 }
//             }
//         }
//     }
// }

// first pos that should be set to 0 O(n)
// void moveZeroes(vector<int>& nums) {
//     int pos = 0;
//     for (int i = 0; i < (int)nums.size(); i++) {
//         if (nums[i] != 0) {
//             nums[pos++] = nums[i];
//         }
//     }

//     for(;pos < nums.size(); pos++) {
//         nums[pos] = 0;
//     }
// }

//last non-zero position with swap O(n)
// void moveZeroes(vector<int>& nums) {
//     int pos = 0;
//     for (int i = 0; i < (int)nums.size(); i++) {
//         if (nums[i] != 0 && i != pos) {
//             swap(nums[pos++], nums[i]);
//         }
//     }
// }

//using stl-stable_partition & compare function customsied O(n)
// bool compareNonZero(int x){
//     return (x !=0);
// }
// void moveZeroes(vector<int>& nums) {
//     stable_partition(nums.begin(), nums.end(), compareNonZero);
// }

//using stl-stable_partition & lambda O(n)
// void moveZeroes(vector<int>& nums) {
//     stable_partition(nums.begin(), nums.end(), [](int x){return (x != 0);});
// }

//
//using stl-stable_partition and logical_not during reverse traversal
void moveZeroes(vector<int>& nums) {
    stable_partition(nums.rbegin(), nums.rend(), logical_not<int>());
}

int main()
{
    int nums[] = {0,1,0,3,12};
    vector<int> array(nums, nums + 5);

    moveZeroes(array);

    //print
    std::cout << "[" ;
    for (int i = 0; i < (int)array.size(); i++) {
        std::cout << array[i];
        if (i != (int)array.size() - 1) {
            std::cout << ","; 
        }   
    }
    std::cout << "]" <<std::endl;

    return 0;
}