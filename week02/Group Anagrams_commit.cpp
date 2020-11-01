//https://leetcode-cn.com/problems/group-anagrams/

#include <iostream>
#include <sstream>
#include <iterator>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>


using namespace std;


//1.使用unorder_map作为临时容器1 O(nklongk) - 推荐
//-建立一个unordered_map<string, vector<string>>，key就是排序后的string，value时一个vector，用来存放属于同一组异位词的原始字符串。
//-遍历原始字符串数组，先将每个遍历的字符串排序，然后根据排序后的字符串作为key在unordered_map里分组并保存原始的字符串。
//-最后遍历unordered_map将数据全部赋给结果vector即可
// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         unordered_map<string, vector<string>> container;
//         vector<vector<string>> res;


//         for (auto &it : strs) {
//             string temp = it;
//             sort(temp.begin(), temp.end());
//             container[temp].push_back(it);
//         }


//         for (auto &it : container) {
//             res.push_back(it.second);
//         }


//         return res;
//     }
// };


//2.使用unorder_map作为临时容器2 O(nklongk) - 推荐(最优)
//-原理同第一个方法，但建立一个unordered_map<string, int>，key就是排序后的string，value为index，用来表示在结果vector里的index。
//-遍历原始字符串数组，先将每个遍历的字符串排序，然后根据排序后的字符串作为key在unordered_map里分组并通过的得到的index，直接将原始字符串放入结果vector相应的组里。
//-最后返回结果vector即可。
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> container;
        vector<vector<string>> res;
        int groupID = 0;


        for (auto &it : strs) {
            string temp = it;
            sort(temp.begin(), temp.end());
            if (container.find(temp) == container.end()) {
                vector<string> group = {it};
                res.push_back(group);
                container[temp] = groupID++;
            }
            else {
                res[container[temp]].push_back(it);
            }
        }
        return res;
    }
};



int main() {
    vector<string> array = {"eat", "tea", "tan", "ate", "nat", "bat"};
    //vector<string> array = {"bdddddddddd", "bbbbbbbbbbc"};
    Solution solution;
    vector<vector<string>> result = solution.groupAnagrams(array);


 //print
    std::cout << "[";
    for (int i = 0; i < (int)result.size(); i++) {
        std::cout << "[";
        for (int j = 0; j < (int)result[i].size(); j++) {
            std::cout << result[i][j];
            if (j != (int)result[i].size() - 1) {
                std::cout << ",";
            } 
        }  
        std::cout << "]";
        if (i != (int)result.size() - 1) {
                std::cout << ",";
        } 
    }
    std::cout << "]" <<std::endl;
    return 0;
}