// Triplet Sum in Array
// Medium Accuracy: 49.0% Submissions: 100k+ Points: 4
// Given an array arr of size n and an integer X. Find if there's a triplet in the array which sums up to the given integer X.

// Example 1:

// Input:
// n = 6, X = 13
// arr[] = [1 4 45 6 10 8]
// Output:
// 1
// Explanation:
// The triplet {1, 4, 8} in
// the array sums up to 13.
// Example 2:

// Input:
// n = 5, X = 10
// arr[] = [1 2 4 3 6]
// Output:
// 1
// Explanation:
// The triplet {1, 3, 6} in
// the array sums up to 10.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function find3Numbers() which takes the array arr[], the size of the array (n) and the sum (X) as inputs and returns True if there exists a triplet in the array arr[] which sums up to X and False otherwise.

// Expected Time Complexity: O(n2)
// Expected Auxiliary Space: O(1)
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find if there exists a triplet in the
    // array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        // Your Code Here
        sort(A, A + n);
        int l, r;
        for (int i = 0; i < n - 2; i++)
        {
            l = i + 1;
            r = n - 1;
            while (l < r)
            {
                if (A[i] + A[l] + A[r] == X)
                    return true;
                if (A[i] + A[l] + A[r] < X)
                    l++;
                else
                    r--;
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, X;
        cin >> n >> X;
        int i, A[n];
        for (i = 0; i < n; i++)
            cin >> A[i];
        Solution ob;
        cout << ob.find3Numbers(A, n, X) << endl;
    }
}
// } Driver Code Ends