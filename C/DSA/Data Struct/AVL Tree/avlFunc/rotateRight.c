#include <stdio.h>
#include "../tree.h"

NODE *rotateRight(NODE *root) {
    NODE *leftChildRoot = root->left;
    NODE *leftRightChild = leftChildRoot->right;

    leftChildRoot->right = root;
    root->left = leftRightChild;

    root->height = 1 + ((getHeight(root->left) > getHeight(root->right)) 
    ? getHeight(root->left) : getHeight(root->right));
    leftChildRoot->height = 1 + ((getHeight(leftChildRoot->left) > getHeight(leftChildRoot->right)) 
    ? getHeight(leftChildRoot->left) : getHeight(leftChildRoot->right));

    return leftChildRoot;
}