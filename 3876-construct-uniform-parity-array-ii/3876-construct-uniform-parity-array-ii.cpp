class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool isOdd = false;
        int small= nums1[0];
        for(int i=0; i<nums1.size(); i++){
            if(nums1[i]%2 != 0) isOdd = true;
            small = min(small, nums1[i]);
        }

        if(isOdd){
            if(small %2 == 0){
                return false;
            }
        }
        return true;
    }
};