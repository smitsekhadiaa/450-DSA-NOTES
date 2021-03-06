// Knapsack with Duplicate Items
// EasyAccuracy: 53.4%Submissions: 37807Points: 2
// Given a set of N items, each with a weight and a value, represented by the array w[] and val[] respectively. Also, a knapsack with weight limit W.
// The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.
// Note: Each item can be taken any number of times.

 

// Example 1:

// Input: N = 2, W = 3
// val[] = {1, 1}
// wt[] = {2, 1}
// Output: 3
// Explanation: 
// 1.Pick the 2nd element thrice.
// 2.Total profit = 1 + 1 + 1 = 3. Also the total 
//   weight = 1 + 1 + 1  = 3 which is <= W.
 

// Example 2:

// Input: N = 4, W = 8
// val[] = {1, 4, 5, 7}
// wt[] = {1, 3, 4, 5}
// Output: 11
// Explanation: The optimal choice is to 
// pick the 2nd and 4th element.
 

// Your Task:
// You do not need to read input or print anything. Your task is to complete the function knapSack() which takes the values N, W and the arrays val[] and wt[] as input parameters and returns the maximum possible value.

 

// Expected Time Complexity: O(N*W)
// Expected Auxiliary Space: O(W)

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int solve(int N, int W, int val[], int wt[], vector<vector<int>> &dp)
    {
        if (N == 0 || W == 0)
        {
            return 0;
        }
        if (dp[N][W] != -1)
        {
            return dp[N][W];
        }
        else
        {
            if (wt[N - 1] <= W)
            {
                return dp[N][W] = max(val[N - 1] + solve(N, W - wt[N - 1], val, wt, dp), solve(N - 1, W, val, wt, dp));
            }
            else
            {
                return dp[N][W] = solve(N - 1, W, val, wt, dp);
            }
        }
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(N + 1, vector<int>(W + 1, -1));
        return solve(N, W, val, wt, dp);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, W;
        cin >> N >> W;
        int val[N], wt[N];
        for (int i = 0; i < N; i++)
            cin >> val[i];
        for (int i = 0; i < N; i++)
            cin >> wt[i];

        Solution ob;
        cout << ob.knapSack(N, W, val, wt) << endl;
    }
    return 0;
}
// } Driver Code Ends