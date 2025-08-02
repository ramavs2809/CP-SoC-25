//http://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/?source=submission-ac
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int c=prices[0],p=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>=c){p+=(prices[i]-c);c=prices[i];}
            else{c=prices[i];}
        }
        return p;
    }
};