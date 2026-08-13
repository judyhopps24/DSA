class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> indegrees(numCourses,0); 
        int n = prerequisites.size();
        for(int i=0;i<n;i++){
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegrees[prerequisites[i][0]]++;
        }

        for(auto x: adjList){
            for(auto y: x)
                cout<<y<<" ";
        }
        cout<<"\n";

        for(auto x: indegrees){
            cout<<x<<" ";
        }
        cout<<"\n";

        queue<int> q;


        for(int i=0;i<numCourses;i++){
            if(indegrees[i]==0){
                q.push(i);
            }
        }
       
        while(!q.empty()){
            int top = q.front();
            q.pop();

            for(auto x: adjList[top]){
                indegrees[x]--;
                if(indegrees[x]==0){
                    q.push(x);
                }
            }
        }


        for(auto x:indegrees){
            if(x>0)
                return false;
        }
        return true;
    }
};
