#include <iostream>
#include "node.h"
#include "map.h"
#include "bst_map.h"
#include "main.h"
#include "string"
#include "list"

enum TreeType{
    UNKNOWN,
    BST_MAP,
    AVL_MAP,
    STD
};

// Variables to store the current setup
int ngram_size;
std::string folder_path;
TreeType tType = UNKNOWN;

int main(int argc, char* argv[]){
    fetch_argument(argc, argv);
    print_setup();
    print_setup();
    print_setup();

}

/**
 * @brief Function to fetch user arguments which specifies the setup
 * @return 1 if success, 0 if fail
 */
int fetch_argument(int argc, char* argv[]){
    std::string current_prefix;
    int i = 0;

    while(i < argc){
        std::string input = std::string(argv[i]);
        // If prefix
        if (input.at(0) == '-'){
            current_prefix = input;
        }

        // If argument
        else if (!input.empty()){
            if (current_prefix.compare("-d") == 0){
                folder_path = input;
            }
            else if (current_prefix.compare("-map") == 0){
                if (input.compare("AVL") == 0){
                    tType = AVL_MAP;
                }
                else if(input.compare("BST") == 0){
                    tType = BST_MAP;
                }
                else{
                    tType = STD;
                }
            }
        }
        else{
            return 0;
        }
        i++;
    }
    return 1;
}

void print_setup(void){
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
            break;
        default:
            std::cout << "ERROR when assigning tree-type" << std::endl;
            break;
    }
}