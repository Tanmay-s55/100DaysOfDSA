class Solution{
public:
    long long int gcd(long long int a, long long int b){
        if(b==0)return a;
        return gcd(b,a%b);
    }
    vector<long long int> minimumSquares(long long int L, long long int B)
    {
        // code here
        vector<long long int> ans;
        long long int k = gcd(L,B);
        ans.push_back((L/k)*(B/k));
        ans.push_back(k);
        return ans;
    }
};