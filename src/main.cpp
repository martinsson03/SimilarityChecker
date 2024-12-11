#include <iostream>
#include "node.h"
#include "map.h"
#include "bst_map.h"

enum TreeType{
    BST_MAP,
    AVL_MAP,
    STD
};

int main(int argc, char* argv[]){
    int ngram_size;
    std::string folder_path;
    TreeType tType;

    // 1 because we want to skip the argument of the program name
    int i = 1;
    while (i < argc) {
        if (argv[i] == "-d"){
            folder_path = argv[i + 1];
        }
        else if (argv[i] == "-map"){
            if (argv[i + 1] == "bst"){
                tType = BST_MAP;
            }
            else if(argv[i + 1] == "avl"){
                tType = AVL_MAP;
            }
            else{
                tType = STD;
            }
        }
        i += 2;
    }
    std::cout << "Document path = " << folder_path << std::endl;
    switch(tType){
        case STD:
            std::cout << "TreeType = STD" << std::endl;
            break;
        case BST_MAP:
            std::cout << "TreeType = BST" << std::endl;
            break;
        case AVL_MAP:
            std::cout << "TreeType = AVL" << std::endl;
        default:
            std::cout << "ERROR when assigning tree-type" << std::endl;

    }
}