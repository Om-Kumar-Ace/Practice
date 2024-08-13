/*************************************************************

    Following is the Binary Tree node structure:

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left),
right(right) {}
    };

*************************************************************/
void inorderTraversel(TreeNode*root,vector<int>&result){
    if(root==nullptr)return;
    inorderTraversel(root->left,result);
    result.push_back(root->data);
    inorderTraversel(root->right,result);
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2) {
  vector<int> inorder1, inorder2, merged;
  inorderTraversel(root1, inorder1);
  inorderTraversel(root2, inorder2);
  int i=0,j=0;
  while (i < inorder1.size() && j < inorder2.size()) {
    if (inorder1[i] <= inorder2[j]) {
      merged.push_back(inorder1[i]);
      i++;
    } else {
      merged.push_back(inorder2[j]);
      j++;
    }
  }

  while (i < inorder1.size()) {
    merged.push_back(inorder1[i]);
    i++;
  }
  while (j < inorder2.size()) {
    merged.push_back(inorder2[j]);
    j++;
  }
  return merged;
}

