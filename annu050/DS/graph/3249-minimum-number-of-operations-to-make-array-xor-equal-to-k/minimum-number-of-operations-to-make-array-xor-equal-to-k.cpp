class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans=0;
        for(int bit=0;bit<=20;bit++){//as 10e6 is there which is for 20 bits 
            int xorvalue=0;
            for(auto el:nums){
                int bitval=(1<<bit)&el;
                xorvalue=xorvalue^bitval;
            }
            int kbitval=(1<<bit)& k;
            if(xorvalue!=kbitval)ans++;
        }
        return ans;
    }
};