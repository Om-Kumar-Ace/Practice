/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	//    Write your code here
    if(root==NULL){
        return -1;
    }
    if(root->data==x||root->data==y){
        return  root->data;
    }
    int leftLCA=lowestCommonAncestor(root->left,  x, y);
    int rightLCA=lowestCommonAncestor(root->right,  x, y);
    if(leftLCA!=-1&&rightLCA!=-1){
        return root->data;
    }
    return (leftLCA!=-1)?leftLCA:rightLCA;
}