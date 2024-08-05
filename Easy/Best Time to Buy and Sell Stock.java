//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
class Solution {
    public int maxProfit(int[] prices) {
    if(prices==null || prices.length==0)
    {
        return 0;
    }
    int maxPro = 0;
    int n = prices.length;
    int minPrice =Integer.MAX_VALUE;

    for (int i = 0; i < n; i++) {
        minPrice = Math.min(minPrice, prices[i]);
        maxPro = Math.max(maxPro, prices[i] - minPrice);
    }
    
    return maxPro;
    }
}
