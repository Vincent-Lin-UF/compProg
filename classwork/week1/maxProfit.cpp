class Solution {
  public:
    int maxProfit(vector<int>& prices){
      int l = 0, mp = 0;
      for(size_t r = 0; r < prices.size(); ++r){
        mp = max(mp, prices[r]-prices[l]);
        l = (prices[l] > prices[r]) ? r : l;
      }
      return mp;
    }
};
