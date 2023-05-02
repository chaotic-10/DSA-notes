    // time complexity : O(N), since we are going at a depth of N nodes at max
    
    int height(TreeNode* A){
    if(!A){
        return 0;
    }
    int lh = height(A->left);
    int rh = height(A->right);
    // below two lines are only diff from height of BT rest is same

    if(lh==-1 || rh==-1) return -1; // if at any moment,  lh or rh returns -1 we return -1
    if(abs(lh-rh)>1) return -1;
    
    return max(lh,rh)+1;
    
}
int Solution::isBalanced(TreeNode* A)
{
    int ans = height(A);
    if(ans == -1){
        return 0;
    }
    else {
        return 1;
    }

}