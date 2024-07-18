#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr, right(nullptr)) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Structure to hold the depth and position of a node
struct NodePos {
    int64_t depth;
    int64_t pos;
};

// Depth-first search to collect leaf nodes
void dfs(TreeNode *node, std::vector<NodePos> &leaves, int64_t depth, int64_t pos) {
    if (node->left != nullptr) {
        dfs(node->left, leaves, depth + 1, pos);
    }

    if (node->right != nullptr) {
        dfs(node->right, leaves, depth + 1, pos | (int64_t(1) << depth));
    }

    if (node->left == nullptr && node->right == nullptr) {
        NodePos p;
        p.depth = depth;
        p.pos = pos;
        leaves.emplace_back(p);
    }
}

// Solution class to count pairs of leaf nodes
class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        std::vector<NodePos> leaves;
        dfs(root, leaves, 0, 0);

        int result = 0;

        for (size_t i = 0; i < leaves.size() - 1; i++) {
            for (size_t j = i + 1; j < leaves.size(); j++) {
                auto fd = leaves[i].depth;
                auto sd = leaves[j].depth;

                auto fp = leaves[i].pos;
                auto sp = leaves[j].pos;

                auto min = std::min(fd, sd);

                auto depthDiff = __builtin_ctzl(fp ^ sp);
                auto diff = (fd - depthDiff) + (sd - depthDiff);

                if (diff == 0 && fd != sd) {
                    diff = std::abs(fd - sd);
                }

                result += diff <= distance;
            }
        }

        return result;
    }
};

// Example usage
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    Solution solution;
    int distance = 3;
    int result = solution.countPairs(root, distance);
    std::cout << "Number of good leaf node pairs: " << result << std::endl;

    return 0;
}
