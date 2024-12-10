#include "map.h"
#include "node.h"

template <typename KeyType, typename ValueType>

class bst_map : public Map<KeyType, ValueType>{
public:
    Node<KeyType, ValueType> root = new Node<KeyType, ValueType>;
public:
    void put(KeyType key, ValueType value){
        root.put(key, value);
    }
    ValueType get(KeyType key){
        root.get(key);
    }
// Private functions    
};