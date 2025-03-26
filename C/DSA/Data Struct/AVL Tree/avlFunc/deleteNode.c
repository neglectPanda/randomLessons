#include <stdio.h>
#include <stdlib.h>
#include "../tree.h"

NODE* deleteNode(NODE *root, int value) {
    // Standard BST delete
    if (root == NULL) return root;

    if (value < root->value)
        root->left = deleteNode(root->left, value);
    else if (value > root->value)
        root->right = deleteNode(root->right, value);
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            NODE *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            NODE *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor 
        NODE *temp = findMinNode(root->right);

        // Copy the inorder successor's content to this node
        root->value = temp->value;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->value);
    }

    // If the tree had only one node, return
    if (root == NULL) return root;

    // Update height
    root->height = 1 + (getHeight(root->left) > getHeight(root->right) 
                        ? getHeight(root->left) : getHeight(root->right));

    // Get balance factor
    int balance = balanceFactor(root);

    // Left Left Case
    if (balance > 1 && balanceFactor(root->left) >= 0)
        return rotateRight(root);

    // Left Right Case
    if (balance > 1 && balanceFactor(root->left) < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // Right Right Case
    if (balance < -1 && balanceFactor(root->right) <= 0)
        return rotateLeft(root);

    // Right Left Case
    if (balance < -1 && balanceFactor(root->right) > 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}