class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n = times.size();
        vector<pair<int,int>>arr;
        for(int i = 0 ; i < n ; i ++){
            arr.push_back({times[i][0],i});
        }
        sort(arr.begin(),arr.end());
        priority_queue<int,vector<int>,greater<int>>avail;
        for(int i = 0 ; i < n ; i++)avail.push(i);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>leaving;
        for(auto i:arr){
            int arrivaltime=i.first;
            int friendind=i.second;
            
            while(!leaving.empty() && leaving.top().first<=arrivaltime){
                avail.push(leaving.top().second);
                leaving.pop();
            }
            
            int chair = avail.top();
            avail.pop();
            if(friendind==targetFriend)return chair;
            leaving.push({times[friendind][1],chair});
        }
return -1;
    }
};
