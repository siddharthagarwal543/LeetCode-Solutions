class Solution {
public:
    bool dfs(vector<vector<int>>&adj,vector<bool>&vis,vector<bool>&path,int e)
    {
        //marking current node visited
        vis[e]=true;
        //adding node to current path
        path[e]=true;
        for(auto it:adj[e])
        {
            if(!vis[it])
            {
                if(dfs(adj,vis,path,it))
                return true;
            }
            //if path[it]=true means the node is already traversed in current path
            else if(vis[it]&&path[it])
            return true;
        }
        path[e]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>>adj(n);
        //creating directed graph
        for(auto it:prerequisites)
        {
            adj[it[0]].push_back(it[1]);
        }
        vector<bool>vis(n,false);
        //for tracking nodes encountered on current path
        vector<bool>path(n,false);
        //traversing graph from each node
        for(int i=0;i<n;i++)
        {
            if(!vis[i]&&dfs(adj,vis,path,i))
            return false;
        }
        return true;

    }
};