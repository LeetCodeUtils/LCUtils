#ifndef LCUTILS_LCTREE_H
#define LCUTILS_LCTREE_H

#include "LCIncludes.h"
#include "LCParse.h"

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(int x, TreeNode *left = nullptr, TreeNode *right = nullptr) : val(x), left(left), right(right) {}
    explicit TreeNode(std::vector<std::string> arr) : left(nullptr), right(nullptr) {
        if (arr.size() == 0)
            return;
        val = LCConvert<int>(arr[0]);
        createTree(this, 0, arr);
    }

private:
    static void createTree(TreeNode* node, int i, std::vector<std::string>& arr) {
        if (node != nullptr) {
            if (2 * i + 1 < arr.size()) {
                if (arr[2 * i + 1] == "null")
                    node->left = nullptr;
                else
                    node->left = new TreeNode(stoi(arr[2 * i + 1]));
                createTree(node->left, 2 * i + 1, arr);
            }


            if (2 * i + 2 < arr.size()) {
                if (arr[2 * i + 2] == "null")
                    node->right = nullptr;
                else
                    node->right = new TreeNode(stoi(arr[2 * i + 2]));
                createTree(node->right, 2 * i + 2, arr);
            }
        }
    }
};

#endif //LCUTILS_LCTREE_H
