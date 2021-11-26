class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        road(graph, 0, path);
        return res ;
    }

    void road(vector<vector<int>>& graph, int s, vector<int> path){       
        //if(graph[s].empty()) return; 放在这结果就全为空
        path.push_back(s);
        if(s == graph.size() - 1) {
            res.push_back(path);
            return;
        }
        for(auto neig : graph[s] ){
            road(graph, neig, path);
        }
     }
};


class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        road(graph, 0, path);
        return res ;
    }

    void road(vector<vector<int>>& graph, int s, vector<int>& path){       
        path.push_back(s);
        if(s == graph.size() - 1) {
            res.push_back(path);
            path.pop_back();
            return;
        }
        for(auto neig : graph[s] ){
            road(graph, neig, path);
        }
        path.pop_back();
     }
};