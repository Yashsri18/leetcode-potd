class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        int arr[n];
        arr[0]=code[0];
        for(int i=1;i<n;i++){
         arr[i]=arr[i-1]+code[i];
        }
        vector<int>ans(n,0);
        if(k==0){
         return ans;
        }
        else if(k>0){
        for(int i=0;i<n;i++){
            if(i+k<n)ans[i]=arr[i+k]-arr[i];
            else{
                ans[i]=arr[n-1]-arr[i]+arr[((i+k)%n)];
            }
        }
        }
        else{
         k=-k;
         for(int i=0;i<n;i++){
              if(i-k>=0){
            ans[i]=arr[i-1]-arr[i-k]+code[i-k];
         }
         else{
         if(i-1<0)   ans[i]=arr[n-1]-arr[n-1-k+i];
         else{
            ans[i]=arr[i-1]+arr[n-1]-arr[n-1-k+i];
         }
         }
         }
       
        }

        return ans;
    }
};