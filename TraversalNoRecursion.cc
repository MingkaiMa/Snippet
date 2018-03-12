#include <iostream>

using namespace std;

void preorderTraversal(TreeNode *root, vector<int>& path)
{
    stack<TreeNode *> s;
    TreeNode *p = root;

    while(p != NULL || !s.empty())
    {
        while(p != NULL)
        {
            path.push_back(p->value);
            s.push(p);
            p = p->left;
        }

        if(!s.empty())
        {
            p = s.top();
            s.pop();
            p = p->right;
        }
    }
}


void inorderTraversal(TreeNode* root, vector<int>& path)
{
    stack<TreeNode*> s;
    TreeNode *p = root;

    while(p != NULL || !s.empty())
    {
        while(p != NULL)
        {
            s.push(p);
            p = p->left;
        }

        if(!s.empty())
        {
            p = s.top();
            path.push_back(p->value);
            s.pop();
            p = p->right;
        }
    }
}

void postorderTraversal(TreeNode* root, vector<int>& path)
{
    stack<TreeNode*> s;
    TreeNode *p = root;
    TreeNode* lastVisit = root;

    while(p != NULL || !s.empty())
    {
        while(p != NULL)
        {
            s.push(p);
            p = p->left;
        }

        p = s.top();

        if(p->right == NULL || p->right == lastVisit)
        {
            path.push_back(p->value);
            s.pop();
            lastVisit = p;
            p = NULL;
        }
        else
        {
            p = p->right;
        }


    }
}