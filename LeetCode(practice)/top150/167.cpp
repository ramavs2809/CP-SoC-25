//https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0,j=numbers.size()-1;
        while(true){
            if((numbers[i]+numbers[j])==target){break;}
            else if((numbers[i]+numbers[j])>target){j--;}
            else{i++;}
        }
        return {i+1,j+1};
    }
};