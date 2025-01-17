class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long answer = 0;
        int minPosition = -1, maxPosition = -1, left = -1;
        for (int i = 0; i < nums.size();i++) {
            if (nums[i] < minK || nums[i] > maxK)
                left = i;
            if (nums[i] == minK) 
                minPosition = i;
            if (nums[i] == maxK)
                maxPosition = i;
            answer += max(0, min(maxPosition, minPosition) - left);
        }
        return answer;
    }
};