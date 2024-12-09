/**
 * Abstract types
 */
template <typename KeyType, typename ValueType>
/**
 * @brief Abstract class to lookup kv-pairs
 */
class Map{
    /**
     * @brief Adds a new kv-pair to the map. Returns true if done sucessful
     */
    virtual bool put(const KeyType& key, const ValueType& value) = 0;
    /**
     * @brief Removes a kv-pair from the map. Returns true if done sucessful
     */
    virtual bool remove(const KeyType& key) = 0;
    /**
     * @brief Function to lookup kv-pairs
     */
    virtual ValueType lookup(const KeyType& key) const = 0;
};