#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//reverse function customized O(n)
// void reverse(vector<int>& nums, int begin, int end) {
//     while (begin < end) {
//         swap(nums[begin++], nums[end--]);
//     }
// }

// void rotate(vector<int>& nums, int k) {
//     if(nums.empty()) { return; }
//     k %= (int)nums.size();
//     reverse(nums, 0, (int)nums.size() - 1);
//     reverse(nums, 0, k - 1);
//     reverse(nums, k, (int)nums.size() - 1);  
// }

//reverse function of stl O(n)
// void rotate(vector<int>& nums, int k) {
//     if(nums.empty()) { return; }
//     k %= (int)nums.size();
//     reverse(nums.begin(), nums.end());
//     reverse(nums.begin(), nums.begin() + k);
//     reverse(nums.begin() + k, nums.end());
// }

//ring substitution and using gcd
// int gcd(int m, int n) {
//     return n == 0? m : gcd(n, m % n);
// }

// void rotate(vector<int>& nums, int k) {
//     if(nums.empty()) { return; }
//     k %= (int)nums.size();
//     int m = gcd(k, (int)nums.size());

//     for (int pos = 0; m > 0; pos++, m--) {
//         int current = pos;
//         int value = nums[current];
//         do {
//             int next = (current + k) % (int)nums.size();
//             swap(nums[next], value);
//             current = next;
//         }while (current != pos);
//     }
// }

//ring substitution and count of exchanges
void rotate(vector<int>& nums, int k) {
    if (nums.empty()) { return; }
    k %= (int)nums.size();
    int count = 0;

    for(int pos = 0; count < (int)nums.size(); pos++) {
        int current = pos;
        int value = nums[current];
        do {
            int next = (current + k) % (int)nums.size();
            swap(nums[next], value);
            current = next;
            count++;
        }while (current != pos);
    }
}



int main() {
    int nums[] = {1,2,3,4,5,6,7};
    std::vector<int> array(nums, nums + 7);
    int k = 3;

    // int nums[] = {-1,-100,3,99};
    // std::vector<int> array(nums, nums + 4);
    // int k = 2;

    rotate(array, k);

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