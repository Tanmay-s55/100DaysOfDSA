class Solution{
public:
    int minCost(vector<vector<int>> &costs) {
        // tabulation
        int k = costs[0].size(),n = costs.size();
        if(k==1 && n!=1)return -1;
        if(n==1 && k==1)return costs[0][0];
        vector<vector<int>> dp(n,vector<int>(k));
        int mini=INT_MAX,smini = INT_MAX,ind=0;
        for(int i=0;i<k;i++){
            dp[0][i] = costs[0][i];
            if(dp[0][i] <= mini){
                smini = mini;
                mini = dp[0][i];
                ind = i;
            }else if(dp[0][i] < smini && dp[0][i] != mini){
                smini = dp[0][i];
            }
        }
        for(int i=1;i<n;i++){
            int mini2=INT_MAX,smini2=INT_MAX,ind2=0;
            for(int j=0;j<k;j++){
                if(j!=ind){
                    dp[i][j] = costs[i][j]+mini;
                }else{
                    dp[i][j] = costs[i][j]+smini;
                }
                if(dp[i][j] <= mini2){
                    smini2 = mini2;
                    mini2 = dp[i][j];
                    ind2 = j;
                }else if(dp[i][j] < smini2 && dp[i][j] != mini2){
                    smini2 = dp[i][j];
                }
            }
            mini = mini2;
            smini = smini2;
            ind = ind2;
        }
        return mini;
    }
};