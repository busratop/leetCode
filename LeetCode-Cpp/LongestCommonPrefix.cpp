class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string l = "";

        sort(strs.begin(),strs.end());
        int n=strs.size();

        for(int i=0; i<min(strs[0].size(),strs[n-1].size()); i++){
            if(strs[0][i]!=strs[n-1][i]){
                break;
            }
            l += strs[0][i];
        }
        return l;
    }
};