#ifndef MAP_H
#define MAP_H
/**
 * Abstract types
 */
template <typename KeyType, typename ValueType>
class Map{
public:
    /**
     * @brief Adds a new kv-pair to the map. Returns true if done sucessful
     */
    virtual void put(const KeyType& key, const ValueType& value) = 0;
    /**
     * @brief Function to lookup kv-pairs
     */
    virtual ValueType* get(const KeyType& key) const = 0;
};
#endif