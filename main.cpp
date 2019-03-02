class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> res;
        if(n <=2)
        {
            for(int i = 0;i < n ; i++)
            {
                res.push_back(i);
            }
            return res;
        }
        vector<unordered_set<int>> graph(n);
        int *node = new int [n];
        for(int i = 0;i < n; i++)
        {
            node[i] = 0;
        }
        for(auto i = edges.begin(); i != edges.end(); i++)
        {
            node[(*i).first] ++;
            node[(*i).second] ++;
            graph[(*i).first].insert((*i).second);
            graph[(*i).second].insert((*i).first);
        }
        queue<int> lis;
        for(int i=0; i< n; i++)
        {
            if(node[i] == 1)
            {
                lis.push(i);
            }
        }
        while(n > 2)
        {
            int l = lis.size();
            n = n - l;
            for(int ii = 0; ii < l; ii ++)
            {
                int i = lis.front();
            auto it = graph[i].begin(); 
                    node[*it] --; 
                graph[*it].erase(i);
                if(node[*it] == 1)
                {
                    lis.push(*it);
                }
            node[i] = 0;
            lis.pop();
            }
        }
        
       while(!lis.empty())
       {
           res.push_back(lis.front());
           lis.pop();
       }
            
        return res;
    }
};
