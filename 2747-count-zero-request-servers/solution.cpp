class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int l=logs.size();
        sort(logs.begin(),logs.end(),[&](vector<int>&a,vector<int>&b){
            return a[1]<b[1];
        });
        vector<pair<int,int>>q;
        int ql=queries.size();
        for(int i=0;i<ql;i++){
            q.push_back({queries[i],i});
        }
        sort(q.begin(),q.end());
        unordered_map<int,int>mp;
        vector<int>ans(ql,0);
        int ll=0,r=0;       
        for(int i=0;i<ql;i++){
            int st=q[i].first-x;
            int en=q[i].first;
            while(r<l && logs[r][1]<=en){
                mp[logs[r][0]]++;
                r++;
            }
            while(ll<r && logs[ll][1]<st){
                mp[logs[ll][0]]--;
                if(mp[logs[ll][0]]==0){
                    mp.erase(logs[ll][0]);
                }
                ll++;
            }
            ans[q[i].second]=n-mp.size();
        }
        return ans;
    }
};