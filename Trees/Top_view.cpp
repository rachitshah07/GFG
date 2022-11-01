class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        if(!root) return {};
        queue<pair<Node *,int>> q;
        q.push({root,0});
        map<int,int> m;
        
        while(!q.empty()){
            auto i = q.front();
            q.pop();
            Node *node = i.first;
            int axis = i.second;
            if(!m[axis]) m[axis] = node->data;
            if(node->left) q.push({node->left,axis-1});
            if(node->right) q.push({node->right,axis+1});
        }
        
        vector<int> a;
        for(auto x:m) a.push_back(x.second);
        return a;
    }

};
