class Solution {
public:
    int sum ;
    int dp[21][2001];
    int solve(int i , int cur , vector<int> & nums , int tg){
        if(cur >= 2001)return 0;
        if(i == nums.size()){
            int res =  cur - (sum- cur);
            if(res == tg)return 1;
            return 0;
        }
        if(dp[i][cur] != -1)return dp[i][cur];
        int p = solve(i+1, cur+ nums[i], nums, tg);
        int np = solve(i+1, cur , nums , tg);
        return dp[i][cur] =  (p+np);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        sum = accumulate(nums.begin(), nums.end(),0);
        memset(dp , -1 , sizeof(dp));
        return solve(0, 0, nums, target);
    }
};
