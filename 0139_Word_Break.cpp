class Solution 
{
private:
    unordered_map<string, bool> vis;
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {   
        if(s.size() == 0 || wordDict.size() == 0)
            return false;
        return dfs(s, wordDict, 0);
    }
    bool dfs(string s, vector<string>& wordDict, int idx)
    {
        if(vis.count(s) && vis[s] == true)
            return true;
        if(vis.count(s) && vis[s] == false)
            return false;
        if(s == "")
            return vis[s] = true;
        else if(idx == wordDict.size())
            return vis[s] = false;
        if(s.substr(0, wordDict[idx].size()) == wordDict[idx])
        {
            if(dfs(s.substr(wordDict[idx].size()), wordDict, 0) || 
                dfs(s, wordDict, idx + 1))
            {
                return vis[s] = true;
            }
        }
        else
        {
            if(dfs(s, wordDict, idx + 1))
            {
                return vis[s] = true;
            }
        }
        return vis[s] = false;
    }
};