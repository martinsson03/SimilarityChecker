#ifndef NODE_H
#define NODE_H
template <typename KeyType, typename ValueType>
class Node{
public:
    KeyType key;
    ValueType value;
    Node* left_child;
    Node* right_child;
    int size;

    Node(const KeyType& k, const ValueType& v, int s = 1)
        : key(k), value(v), left_child(nullptr), right_child(nullptr), size(s) {}

    /**
     * Functions
     */
public:
    void put(KeyType key, ValueType value){
        if (key < this->key){
            if(this->left_child){
                this->left_child->put(key, value);
            }
            else{
                this->left_child = new Node(key, value);
            }
        }
        if (key > this->key){
            if (this->right_child){
                return this->right_child->put(key,value);
            }
            else{
                this->right_child = new Node(key,value);
            }
        }
        // If the current node has the same key as key
        else{
            this->value = value;
        }
    }

    ValueType get(KeyType key){
        if (key < this->key){
            if(this->left_child){
                return this->left_child->get(key);
            }
            return NULL;
        }
        if (key > this->key){
            if(this->right_child){
                return this->right_child->get(key);
            }
            return NULL;
        }
        return this->value;
    }

private:
    /**
     * Function to update size. In case of AVL-node, also updated height
     */
    void update_height_and_size(){
        this->size = (this->left_child ? this->left_child->size : 0) + 
             (this->right_child ? this->right_child->size : 0) + 1;
    }
};
#endif