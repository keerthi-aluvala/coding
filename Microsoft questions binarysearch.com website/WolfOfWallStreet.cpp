/* Wolf of Wall Street  Question 57 of 1031

Given a list of integers prices representing the stock prices of a company in chronological order, return the maximum profit you could have made from buying and selling that stock once.

You must buy before you can sell it.

Note: You are not required to buy or sell the stock.

Constraints

n = 100,000 where n is the length of prices
Example 1
Input
prices = [9, 11, 8, 5, 7, 10]
Output
5
Explanation
You can buy at 5 and sell at 10.

Example 2
Input
prices = [1, 2, 3, 4, 5, 6, 7, 8, 9]
Output
8
Explanation
You can buy at 1 and sell at 9.

Example 3
Input
prices = [9, 8, 7, 6, 5, 4, 3, 2, 1]
Output
0
Explanation
The stock's only going down so we don't buy at all.

*/



int solve(vector<int>& prices) 
{
    int min1 = INT_MAX;
    int profit = 0;
    for(int i: prices)
    {
        min1 = min(min1, i);
        profit = max(profit, i-min1);
    }
    return profit;
}
