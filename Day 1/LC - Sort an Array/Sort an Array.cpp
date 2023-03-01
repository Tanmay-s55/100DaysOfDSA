class Solution {
public:
    void merge(int lo,int mid,int hi,vector<int>& nums){
        int i,j,k;
        int left = mid-lo+1,right = hi-mid;

        vector<int> leftArr(left),rightArr(right);
        for(int x=0;x<left;x++){
            leftArr[x] = nums[x+lo];
        }
        for(int x=0;x<right;x++){
            rightArr[x] = nums[mid+1+x];
        }
        i=0,j=0,k=lo;
        while(i<left && j<right){
            if(leftArr[i] <= rightArr[j]){
                nums[k] = leftArr[i];
                i++;
            }else{
                nums[k] = rightArr[j];
                j++;
            }
            k++;
        }
        while(i<left){
            nums[k] = leftArr[i];
            k++,i++;
        }
        while(j<right){
            nums[k] = rightArr[j];
            k++,j++;
        }
    }
    void mergeSort(vector<int>& nums,int lo,int hi){
        int mid;
        if(lo<hi){
            mid = (lo+hi)/2;
            mergeSort(nums,lo,mid);
            mergeSort(nums,mid+1,hi);
            merge(lo,mid,hi,nums);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};