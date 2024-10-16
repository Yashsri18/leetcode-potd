// day14
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});
        
        string res = "";
        
        // The condition should check for non-empty queue
        while (!pq.empty()) {
            auto [count, ch] = pq.top(); 
            pq.pop();
            
            if (res.size() > 0 && res.back() == ch) {
                // If the last character is the same as `ch`, check for an alternative
                if (pq.empty()) break;  // If there's no alternative, break out
                
                auto [count2, ch2] = pq.top(); 
                pq.pop();
                
                res += ch2;  // Add the alternative character
                count2--;
                
                if (count2 > 0) pq.push({count2, ch2});
                
                pq.push({count, ch});  // Push `ch` back for future use
            } else {
                // Add the current character
                if (count >= 2) {
                    res += ch; 
                    res += ch;  // Add twice if available
                    count -= 2;
                } else {
                    res += ch;  // Add once
                    count--;
                }
                
                if (count > 0) pq.push({count, ch});  // Push back if more occurrences remain
            }
        }
        
        return res;
    }
};