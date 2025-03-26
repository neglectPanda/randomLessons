#include <stdio.h>
#include "../tree.h"

NODE *insertNode(NODE *root, int value) {
    if(root == NULL) return createNode(value);

    if(value < root->value) {
        root->left = insertNode(root->left, value);
    } else if (value > root->value) {
        root->right = insertNode(root->right, value);
    } else {
        return root; //duplicate value;
    }

    root->height = 1 + ((getHeight(root->left) > getHeight(root->right)) 
    ? getHeight(root->left) : getHeight(root->right));

    int balance = balanceFactor(root);
    root->status = 0;

    // left left 
    if(balance > 1 && value < root->left->value) {
        root->status = 1;
        return rotateRight(root);
    }
    // right right
    if(balance < -1 && value > root->right->value) {
        root->status = 1;
        return rotateLeft(root);
    }
    // left right
    if(balance > 1 && value > root->left->value) {
        root->left = rotateLeft(root->left);
        root->status = 1;
        return rotateRight(root);
    }
    // right left
    if(balance < -1 && value < root->right->value) {
        root->right = rotateRight(root->right);
        root->status = 1;
        return rotateLeft(root);
    }

    return root;
}