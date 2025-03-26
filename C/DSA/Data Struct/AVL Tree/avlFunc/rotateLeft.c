#include <stdio.h>
#include "../tree.h"

NODE *rotateLeft(NODE *root) {
    NODE *rightChildRoot = root->right;
    NODE *rightLeftChild = rightChildRoot->left;

    rightChildRoot->left = root;
    root->right = rightLeftChild;

    root->height = 1 + ((getHeight(root->left) > getHeight(root->right)) 
    ? getHeight(root->left) : getHeight(root->right));
    rightChildRoot->height = 1 + ((getHeight(rightChildRoot->left) > getHeight(rightChildRoot->right)) 
    ? getHeight(rightChildRoot->left) : getHeight(rightChildRoot->right));

    return rightChildRoot;
}