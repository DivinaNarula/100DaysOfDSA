/* Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
 

Example 1:
Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [0]
Output: [0] */

#include <stdio.h>
#include <stdlib.h>

// Definition of TreeNode
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Global pointer
struct TreeNode* prev = NULL;

// Helper function
void helper(struct TreeNode* root) {
    if (root == NULL) return;

    helper(root->right);
    helper(root->left);

    root->right = prev;
    root->left = NULL;

    prev = root;
}

// Flatten function
void flatten(struct TreeNode* root) {
    prev = NULL;   // reset
    helper(root);
}

// Create new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Print flattened list
void printList(struct TreeNode* root) {
    struct TreeNode* curr = root;
    while (curr != NULL) {
        printf("%d -> ", curr->val);
        curr = curr->right;
    }
    printf("NULL\n");
}

// Main function
int main() {
    /*
        Example Tree:
            1
           / \
          2   5
         / \   \
        3   4   6
    */

    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->right = newNode(6);

    flatten(root);

    printf("Flattened List:\n");
    printList(root);

    return 0;
}