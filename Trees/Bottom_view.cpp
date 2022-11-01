class Solution {
  public:
    vector <int> bottomView(Node *root) {
        if(!root) return {};
        
        map<int,int>m;
        queue<pair<Node *,int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto i = q.front();
            q.pop();
            int axis = i.second;
            auto node = i.first;
            m[axis] = node->data;
            if(node->left) q.push({node->left,axis-1});
            if(node->right) q.push({node->right,axis+1});
        }
        
        vector<int>a;
        for(auto i:m) a.push_back(i.second);
        return a;
    }
};
