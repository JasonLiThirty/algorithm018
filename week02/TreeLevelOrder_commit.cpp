//https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal/

#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <queue>

using namespace std;

//Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

//1.利用队列实现广度优先搜索 O(n) - 推荐
//-利用队列作为临时容器，利用其先进先出的特性，在队列取出某节点是，将其子节点放入队列中，这实际上就是树的广度优先遍历方法(DFS)。
//-那如何将每一层的节点保存为一个列表呢，则可以在每次从队列中取数据前，读取当前队列的元素个数，这个个数就是同一层节点的个数，
//-然后利用这个个数，来决定取节点和放入子节点的循环次数。
//-这样就可以保存同一层节点的值到一个列表中，在这个内循环结束之后，将列表保存到返回的大列表当中
// class Solution {
// public:
//     vector<vector<int>> levelOrder(Node* root) {
//         if(root == nullptr) { return {}; }

//         vector<vector<int>> res;
//         queue<Node*> container;

//         container.push(root);
//         while(!container.empty()) {
//             vector<int> levelVal;
//             int levelCount = (int)container.size();
//             for(int i = 0; i < levelCount; i++) {
//                 Node* node = container.front();
//                 levelVal.push_back(node->val);
//                 container.pop();
//                 for(auto &child : node->children) {
//                     container.push(child);
//                 }
//             }
//             res.push_back(levelVal);
//         }
//         return res;
//     }
// };

//2.利用更新每一层的节点来实现层遍历 O(n) - 简洁，巧妙 - 推荐
//-利用一个全局数组来保存每一层的节点，在遍历的过程中来不断更新这个数组
//-同样是判断这个全局数组是否还有元素，因为在遍历节点的过程中一直在更新这个数组，所以也是等到所有节点都遍历完了该全局数组才会为空。
//-在这个全局数组中遍历上一层的节点时，将这些节点的子节点放入到另一个临时数组中，这一层的节点全部遍历完了之后，再将临时数组覆盖掉全局数组的节点，这样就能继续遍历下一层了。
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == nullptr) { return {}; }

        vector<vector<int>> res;
        vector<Node*> upperlever = {root};
        while (!upperlever.empty()) {
            vector<Node*> currentLevel = {};
            vector<int> levelVal = {};
            for (auto &node : upperlever) {
                levelVal.push_back(node->val);
                currentLevel.insert(currentLevel.end(), node->children.begin(), node->children.end());
            }
            res.push_back(levelVal);
            upperlever.assign(currentLevel.begin(), currentLevel.end());
        }
        return res;
    }
};


int main() {
    Node *n3 = new Node(3);
    n3->children.push_back(new Node(5));
    n3->children.push_back(new Node(6));
    Node *root = new Node(1);
    root->children.push_back(n3);
    root->children.push_back(new Node(2));
    root->children.push_back(new Node(4));

    Solution solution;

    vector<vector<int>> result = solution.levelOrder(root);


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