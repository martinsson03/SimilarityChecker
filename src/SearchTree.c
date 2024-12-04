#include "SearchTree.h"
#include <stdlib.h>

int max(int a, int b){
    if (a >=  b){
        return b;
    }
    return a;
}

int get_size(Node* node){
    if (node == NULL){
        return 0;
    }
    
    return node->size;
}

int get_height(Node* node){
    if (node == NULL){
        return 0;
    }
    return node->height;
}

/**
 * @brief Updates the size and height of the current node. Assumes that the children have
 * correct size and height. Not recursive
 */
void update_size_and_height(Node* node){
    node->size = get_size(node->left_child) + get_size(node->right_child) + 1;
    node->height = max(get_height(node->left_child), get_height(node->right_child)) + 1;   
}

/**
 * @brief Creates a new node with the inserted key and value
 * @param key Specifies what key to use
 * @param value Specifies what value to use
*/
Node* create_node(int key, int value){
    Node* ptr = (Node*) malloc(sizeof(Node));
    if (ptr == NULL){
        return NULL;
    }
    ptr->key = key;
    ptr->value = value;
    ptr->height = 1;
    ptr->size = 1;

    ptr->left_child = NULL;
    ptr->right_child = NULL;

    return ptr;
}

Node* put(Node* old_tree, int key, int value){
    old_tree = put_helper(old_tree, key, value);
    //#TODO Create functionality for rotating trees (ALV style)
    return old_tree;
}

/**
 * @brief Helper function to add values to tree. Return pointer to the new root
 */

Node* put_helper(Node* old_tree, int key, int value){
    //Creates a new node 
    if (old_tree == NULL){
        return create_node(key, value);
    }
    else if(old_tree->key < key){
        old_tree->left_child = put_helper(old_tree->left_child, key, value);
        update_size_and_height(old_tree);
        
    }
    else if(old_tree->key > key){
        old_tree->right_child = put_helper(old_tree->right_child, key, value);
        update_size_and_height(old_tree);
    }
    //Change value if key already exists
    else{
        old_tree->value = value;
    }
    return old_tree;
}

/**
 * @brief Function for testing the tree. Test the BST invariant and that the size
 * and height has been calculated correctly.
 * @return 1 if test successed, 0 otherwise
 */
int test_tree(Node* tree){
    //Empty node
    if (tree == NULL){
        return 1;
    }
    //If the test has faild for some child
    if (test_tree(tree->left_child) == 0 || test_tree(tree->right_child) == 0){
        return 0;
    }
    //If no null child, test BST invariant
    if(tree->left_child != NULL && tree->right_child != NULL){
        if (tree->left_child->key > tree->right_child->key){
            return 0;
        }
    }
    //Check size
    if(tree->size != (get_size(tree->left_child) + get_size(tree->right_child) + 1)){
        return 0;
    }
    //Check height
    if (tree->height != max(get_height(tree->left_child), get_height(tree->right_child)) + 1){
        return 0;
    }
    //All tests passed
    return 1;
}