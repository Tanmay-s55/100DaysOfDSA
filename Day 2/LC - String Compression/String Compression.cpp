class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        if(n==1)
            return 1;
        int ind=0,i=0;
        while(i<n){
            char ch = chars[i];
            int cnt=0;
            while(i<n && chars[i]==ch){
                i++,cnt++;
            }
            chars[ind++] = ch;
            if(cnt>1){
                string num = to_string(cnt);
                for(auto c: num)
                    chars[ind++] = c;   
            }
        }
        return ind;
    }
};