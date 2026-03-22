/* You are given the root of a binary search tree (BST) and an integer val.
Find the node in the BST that the node's value equals val and return the subtree rooted with that node. 
If such a node does not exist, return null.

Example 1:
Input: root = [4,2,7,1,3], val = 2
Output: [2,1,3]

Example 2:
Input: root = [4,2,7,1,3], val = 5
Output: [] */

#include <stdio.h>
#include <stdlib.h>

/* Definition of Tree Node */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/* Create a new node */
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* Insert into BST */
struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL)
        return createNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

/* Search in BST */
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    if (root == NULL || root->val == val)
        return root;

    if (val < root->val)
        return searchBST(root->left, val);
    else
        return searchBST(root->right, val);
}

/* Preorder traversal to print subtree */
void preorder(struct TreeNode* root) {
    if (root == NULL)
        return;

    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

/* Main function */
int main() {
    int n, val, x;

    struct TreeNode* root = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter BST elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    printf("Enter value to search: ");
    scanf("%d", &val);

    struct TreeNode* result = searchBST(root, val);

    if (result == NULL) {
        printf("Output: []\n");
    } else {
        printf("Subtree (Preorder): ");
        preorder(result);
        printf("\n");
    }

    return 0;
}