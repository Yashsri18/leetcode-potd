//day 15 
class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        priority_queue<pair<char,int>>pq;
        for(auto i =0;i<s.size();i++){
            pq.push({s[i],i});
        }
        for(int i = 0 ;i<n;i++){
            
            while(pq.size() && pq.top().second<i){
                pq.pop();
            }
            if(pq.size() && pq.top().first>s[i]){
                swap(s[i],s[pq.top().second]);
                return stoi(s);
            }

        }
        return stoi(s);
    }
};