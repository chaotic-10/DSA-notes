
class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node)
    {
        // base case
        if(node==NULL){
            return 0;
        }
        int left_height = height(node->left);
        int right_height = height(node->right);
        return max(left_height,right_height)+1;
    }
};