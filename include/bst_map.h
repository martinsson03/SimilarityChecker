#ifndef BST_MAP_H
#define BST_MAP_H

#include "map.h"
#include "node.h"

template <typename KeyType, typename ValueType>
class bst_map : public Map<KeyType, ValueType>{
public:
    bst_map() : root(nullptr) {}

    Node<KeyType, ValueType>* root;


    void put(const KeyType& key, const ValueType& value) override{
        if (root){
            root->put(key, value);
        }
        else{
            root = new Node<KeyType, ValueType>(key, value); 
        }
    }

    ValueType get(const KeyType& key) const override{
        if (root){
            return root->get(key);
        }
        // If not found
        else{
            throw std::runtime_error("Tree is empty, key not found");
        }
    }

    ~bst_map(){
        delete_tree(root);
    }
    void delete_tree(Node<KeyType,ValueType>* node){
        if (!node) return;
        delete_tree(node->left_child);
        delete_tree(node->right_child);
        delete node;
    }    
};
#endif