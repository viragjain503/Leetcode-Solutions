/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool storePath(TreeNode* root, TreeNode* p,vector<TreeNode*>& v){
        
        // cout<<root->val<<" ";
        v.push_back(root);
        // cout<<v.size()<<endl;
        if(p->val == root->val){
            return true; 
        }
        
        if(root->left){
            if(storePath(root->left,p,v) == true){
                return true;
            }
            v.pop_back();
        } 
        // cout<<root->val<<" in between "<<endl;
        if(root->right){
            if( storePath(root->right,p,v) == true){
                return true;
            }
            v.pop_back();
        }

        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> v1; 
        vector<TreeNode*> v2; 
        storePath(root,p,v1);
        // cout<<"askdnaskd"<<endl;
        storePath(root,q,v2);
        // cout<<"Hii"<<endl;
        int i=0;
        int j=0;
        while(i < v1.size() && j < v2.size() && v1[i]->val == v2[j]->val){
            cout<<v1[i]->val<<" "<<v2[i]->val<<endl;
            // if(i == v1.size()-1){
            //     break;
            // }
            // if(j == v2.size()-1){
            //     break;
            // }
            i++;
            j++;
        }
        return v1[i-1]; 
    }
};

