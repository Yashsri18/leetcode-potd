class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        for(int i = 0; i < arr.size(); i++){
            int doubleN = arr[i] * 2;
            int left = 0, right = arr.size() - 1, mid;
            if(doubleN == 0){
                auto it = find(arr.begin() + i + 1, arr.end(), 0);
                if(it != arr.end())
                    return true;
                continue;
            }
            while(left <= right){
                mid = (left + right) / 2;
                if(arr[mid] == doubleN)
                    return true;
                else if(arr[mid] > doubleN)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        return false;
    }
};