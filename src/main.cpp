#include <iostream>
#include "node.h"
#include "map.h"
#include "bst_map.h"
#include "main.h"
#include "string"
#include "list"

enum TreeType{
    BST_MAP,
    AVL_MAP,
    STD
};

// Variables to store the current setup
int ngram_size;
std::string folder_path;
TreeType tType;

int main(int argc, char* argv[]){
    
}

/**
 * @brief Function to fetch user arguments which specifies the setup
 * @return 1 if success, 0 if fail
 */
int fetch_argument(int argc, char* argv[]){
    std::string current_prefix = nullptr;
    int i = 0;

    while(i < argc){
        std::string input = std::string(argv[i]);
        // If prefix
        if (input.at(0) == '-'){
            current_prefix = input;
        }

        // If argument
        else if (input != nullptr){
            
        }

    }


    std::list<std::string> input;
    int i = 0;
    // Insert all arguments to the input list
    while (i < argc){
        std::string input_string = argv[i];
        input.push_back(input_string);
    }

    i = 0;
    std::list<std::string>::iterator it = input.begin();
    while(it != input.end()){
        std::string prefix = *it;
        it++;
        if (it == input.end()){
            break;
        }
        std::string argument = *it;
        it++;

        if (prefix.compare("-d") == 0){
            folder_path = argument;
        }
        if (prefix.compare("-map") == 0){
            if (argument.compare("AVL")){
                tType = AVL_MAP;
            }
            else if (argument.compare("BST")){
                tType = BST_MAP;
            }
            else{
                tType = STD;
            }
        }
    }
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
        default:
            std::cout << "ERROR when assigning tree-type" << std::endl;
    }
}