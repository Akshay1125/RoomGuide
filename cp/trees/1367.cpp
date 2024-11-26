/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
public:
    void dfs( TreeNode* root,vector<int> &path, vector<vector<int>>& v){
        
        
        if(root->left==NULL && root->right==NULL){
            v.push_back(path);
            return;
        }
        if(!root) return;
        path.push_back({root->val});
        dfs(root->left,v);
        dfs(root->right,v);

    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        
        vector<vector<int>> v;
        vector<int> path;
        dfs(root,path,v);
        vector<int> p;
        //new listnode//
        temp = head;

        while(head){
            p.push_back(head->val);
            head = head->next;
        }
        for(auto i : v){
            if(i==p) return true;
        }
        return false;

        
    }
};