#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int least_price=prices[0];
        int ans=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>least_price){
                ans=max(ans,prices[i]-least_price);
            }
            else{
                least_price=prices[i];
            }
        }
        return ans;
    }
};
int main(){
    Solution sol;
    vector<int>prices={7,1,5,3,6,4};
    cout<<sol.maxProfit(prices);
}