class Solution {
public:
//Just iterate the array calculate the current Profit by selling price(curr index price) - buying price
//Whenever you find the current Profit is less than 0 it means there is better buying price available 
//So change the buying price to current index price
//Now if the current Profit is more than the max Profit till now, then change the max Profit equal to current profit
//Which means basically you are selling the stock at this current index
    int maxProfit(vector<int>& prices) {
        int lengthOfPrices = prices.size();
        int buyPrice = prices[0];
        int maxProfit = 0,currProfit=0;
      for(int i=1;i<lengthOfPrices;i++){
        currProfit = prices[i]-buyPrice; //Price[i] is Selling Price
        if(currProfit<=0)//lesser buying Price in Current index
        buyPrice = prices[i];
        else if(currProfit>maxProfit)
        maxProfit = currProfit;
      }
      return maxProfit;  
    }
};
