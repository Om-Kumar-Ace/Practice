/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    struct MTreeNode {
        long sibSum;
        TreeNode* node;
        MTreeNode(long sibSum, TreeNode* node) : sibSum(sibSum), node(node) {}
    };

public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        unordered_map<int, long> depthSumMp;
        deque<MTreeNode> lvlQ;

        lvlQ.push_back(MTreeNode(root->val, root));
        int currLvl = 0;
        depthSumMp[currLvl] = root->val * 1l;

        while (!lvlQ.empty()) {
            int lvlSize = lvlQ.size();
            long nextLvlSum = 0l;

            while (lvlSize-- > 0) {
                long sibSum = 0l;
                MTreeNode currMNode = lvlQ.front();
                lvlQ.pop_front();
                
                TreeNode* currNode = currMNode.node;

                if (currNode->left) sibSum += currNode->left->val;
                if (currNode->right) sibSum += currNode->right->val;

                if (currNode->left) {
                    nextLvlSum += currNode->left->val;
                    lvlQ.push_back(MTreeNode(sibSum, currNode->left));
                }

                if (currNode->right) {
                    nextLvlSum += currNode->right->val;
                    lvlQ.push_back(MTreeNode(sibSum, currNode->right));
                }

                currNode->val = static_cast<int>(depthSumMp[currLvl] - currMNode.sibSum);
            }

            depthSumMp[++currLvl] = nextLvlSum;
        }
        return root;
    }
};