template <typename KeyType, typename ValueType>
//requires std::totally_ordered<KeyType>
/**
 * @brief Class to structure nodes
 */
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
    void get_size(){
        return size;
    }

    void set_size(int new_size){
        size = new_size;
    }

    ValueType get_value(){
        return value;
    }

    void set_value(ValueType new_value){
        value = new_value;
    }

    KeyType get_key(){
        return key;
    }

    Node* get_left_child(){
        return left_child;
    }
    void set_left_child(Node* new_left_child){
        left_child = new_left_child;
    }
    
    Node* get_right_child(){
        return right_child;
    }
    
    void set_right_child(Node* new_right_child){
        right_child = new_right_child;
    }

    bool put(KeyType key, ValueType value){
        put_helper(this, key, value);
        return true;
    }

    bool put_helper(Node* node, KeyType key, ValueType value){
        if (node == nullptr){
            return Node(key, value);
        }
        if (key < node->get_key()){
            return node->set_left_child()
        }
        if (key > node->get_key()){
            return node->set_right_child()
        }
        
    }
};