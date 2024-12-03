#include "SearchTree.h"
#include <stdlib.h>

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

    ptr->left_child = NULL;
    ptr->right_child = NULL;

    return ptr;
}

Node* add_pair(Node* old_tree, int key, int value){
    //Creates a new node
    Node* new_node = create_node(key, value);
    //If unable to create node
    if (new_node == NULL){
        return NULL;
    }

    if (old_tree->key <= key){
        if (old_tree->left_child == NULL){
            old_tree->left_child = new_node;
        }

    }
    if (old_tree->key <= key){
        return add_pair(old_tree->left_child, key, value);
    } 
}