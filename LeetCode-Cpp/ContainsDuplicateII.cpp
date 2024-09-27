class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
      int n = nums.size();
        unordered_map<int, list<int>>myMap;
        for(int i=0; i<n; i++){
            if(myMap.find(nums[i]) != myMap.end()){
                for(auto node: myMap[nums[i]]){
                    if(abs(i-node)<=k){
                        return true;
                    }
                }

            }
            myMap[nums[i]].push_back(i);
        }
       return false;
    }
};
