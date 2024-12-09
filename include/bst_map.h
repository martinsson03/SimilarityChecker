#include "map.h"
#include "node.h"

template <typename KeyType, typename ValueType>
requires std::totally_ordered<KeyType>

class bst_map : public Map<KeyType, ValueType>{
public:
    Node root = nullptr;

    bool put(KeyType key, ValueType value){
        if (root == nullptr){
            root = Node(key, value);
            return true;
        }
        if (root.get_key() < )

    }

};