// all the problems which wants you to traverse till leaf node and then do something, they always have a common base 
// that is,   if(root->left==NULL && root->right==NULL)
// since here we needed to find a path i.e from root to leaf which has a target sum so we used that base case
// tc : o(N)

int func(TreeNode* root,int sum,int a){
     if(root->left==NULL && root->right==NULL)
     {
         if(a+root->val==sum) return 1;
         else  return 0;
     }
   int s1=(root->left==NULL) ? 0:func(root->left,sum,a+root->val);
   int s2=(root->right==NULL) ? 0:func(root->right,sum,a+root->val);
   // Why || ? because ek bhi path se target sum acheive hua to end krdo
     return (s1 || s2);
 }