class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin() ,intervals.end());
        int l = intervals.size();
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for(int i=1;i<l;i++){
            if(intervals[i][0] <= res.back()[1]){
                if(res.back()[1] > intervals[i][1]) continue;
                res.back()[1]=intervals[i][1];
            }else{
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};
