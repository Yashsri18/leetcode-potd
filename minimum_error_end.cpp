class Solution {
public:
    long long minEnd(int n, int x) {
        long long next_ele=x;
        for(int i=1;i<n;i++){
            next_ele=(next_ele+1)|x;
        }
    return next_ele;
    }
};