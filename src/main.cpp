#include <iostream>
#include "node.h"
#include "map.h"
#include "bst_map.h"


int main(int, char**){
    Node<int,int>* node = new Node<int, int>(0, 0);
    node->put(1, 2);
    
    std::cout << node->get(1) << std::endl;
}
