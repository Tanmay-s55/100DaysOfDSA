class Solution {
public:
    int strStr(string hay, string n) {
        if(hay==n)return 0;
        int idx = -1,l=0,i=0,j=0;
        int l1=hay.size(),l2=n.size();
        while(i<l1 && j<l2){
            if(hay[i]==n[j]){
                i++,j++;
            }else{
                l++; //last index where we matched
                i = l;
                j=0,idx=-1; //reset j,and currently needle not found
            }
            if(j==l2){
                idx = l;
                break;
            }
        }
        return idx;
    }
};