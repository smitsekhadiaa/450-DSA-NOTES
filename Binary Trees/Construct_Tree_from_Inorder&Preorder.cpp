// Construct Tree from Inorder & Preorder
// Medium Accuracy: 36.26% Submissions: 70234 Points: 4
// Given 2 Arrays of Inorder and preorder traversal. Construct a tree and print the Postorder traversal.

// Example 1:

// Input:
// N = 4
// inorder[] = {1 6 8 7}
// preorder[] = {1 6 7 8}
// Output: 8 7 6 1
// Example 2:

// Input:
// N = 6
// inorder[] = {3 1 4 0 5 2}
// preorder[] = {0 1 3 4 2 5}
// Output: 3 4 1 5 2 0
// Explanation: The tree will look like
//        0
//     /     \
//    1       2
//  /   \    /
// 3    4   5
// Your Task:
// Your task is to complete the function buildTree() which takes 3 arguments(inorder traversal array, preorder traversal array, and size of tree n) and returns the root node to the tree constructed. You are not required to print anything and a new line is added automatically (The post order of the returned tree is printed by the driver's code.)

// Expected Time Complexity: O(N*N).
// Expected Auxiliary Space: O(N)
// { Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printPostOrder(Node *root)
{
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution
{
public:
    Node *ConstructTree(int pre[], int prestart, int preend, int in[], int instart, int inend, map<int, int> &mp)
    {
        if (prestart > preend || instart > inend)
        {
            return NULL;
        }
        Node *root = new Node(pre[prestart]);
        int inroot = mp[root->data];
        int numsleft = inroot - instart;
        root->left = ConstructTree(pre, prestart + 1, prestart + numsleft, in, instart, inroot - 1, mp);
        root->right = ConstructTree(pre, prestart + numsleft + 1, preend, in, inroot + 1, inend, mp);
        return root;
    }
    Node *buildTree(int in[], int pre[], int n)
    {
        // Code here
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[in[i]] = i;
        }
        Node *root = ConstructTree(pre, 0, n - 1, in, 0, n - 1, mp);
        return root;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int inorder[n], preorder[n];
        for (int i = 0; i < n; i++)
            cin >> inorder[i];
        for (int i = 0; i < n; i++)
            cin >> preorder[i];
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder, n);
        printPostOrder(root);
        cout << endl;
    }
}
// } Driver Code Ends