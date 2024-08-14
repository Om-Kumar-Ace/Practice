#include <queue>
#include <vector>

int getMaxWidth(TreeNode<int> *root) {
    if (root == nullptr) {
        return 0;
    }

    std::queue<TreeNode<int>*> q;
    q.push(root);
    int maxWidth = 0;

    while (!q.empty()) {
        int levelSize = q.size();
        maxWidth = std::max(maxWidth, levelSize);

        for (int i = 0; i < levelSize; i++) {
            TreeNode<int>* node = q.front();
            q.pop();

            if (node->left != nullptr) {
                q.push(node->left);
            }

            if (node->right != nullptr) {
                q.push(node->right);
            }
        }
    }

    return maxWidth;
}