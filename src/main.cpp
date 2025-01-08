#include <iostream>
#include <filesystem>
#include <string>
#include <direct.h>
#include <fstream>

#include "node.h"
#include "map.h"
#include "bst_map.h"
#include "avl_map.h"
#include "main.h"
#include "list"

#define CWD_BUFFER_SIZE 1024

enum TreeType{
    UNKNOWN,
    BST_MAP,
    AVL_MAP,
    STD
};

using namespace std;

// Variables to store the current setup
int ngram_size;
std::string folder_path;
TreeType tType = UNKNOWN;

// Buffer for the current working directory
char cwd_buffer[CWD_BUFFER_SIZE];

// Maps, initialized as BST from the beginning
bst_map<string, list<string>> ngram_bst_map;
Map<string, list<string>>& ngram_map = ngram_bst_map;

bst_map<list<string>, string> path_bst_map;
Map<list<string>, string>& path_map = path_bst_map;

int main(int argc, char* argv[]){
    // Fetch user input
    if (fetch_argument(argc, argv) == 0){
        cout << "Could not fetch arguments, exits" << endl;
        return 0;
    }
    // Instansiate the maps
    if (init_maps() == 0){
        cout << "Could not init maps" << endl;
        return 0;
    }

    cout << "Init done with the following setup:" << endl;
    print_setup();

    //Build the ngram_map
    try{
        cout << "Building ngram_map" << endl;
        for (const auto &entry : filesystem::directory_iterator(folder_path)){
            string file_path = entry.path().string();
            
            ifstream input_file(file_path);
            
            stringstream buffer;
            buffer << input_file.rdbuf();
            string file_content = buffer.str();

            

        }
    }
    catch(...){
        cout << "Error when reading files... Exiting..." << endl;
        return 0;
    }



    
}

/**
 * @brief Creates map of the different sub classes of map.
 * @return 1 if success, 0 if fail
 */
int init_maps(void){
    if (tType == BST_MAP){
        //No need to change, maps are BST as default
        return 1;
    }
    if(tType == AVL_MAP){
        avl_map<string, list<string>> avl_ngram_map;
        ngram_map = avl_ngram_map;
        avl_map<list<string>, string> avl_path_map;
        path_map = avl_path_map;
        return 1;
    }
    return 0;
}

/**
 * @brief Function to fetch user arguments which specifies the setup
 * @return 1 if success, 0 if fail
 */
int fetch_argument(int argc, char* argv[]){
    std::string current_prefix;
    int input_counter = 3;
    int i = 0;
    while(i < argc){
        std::string input = std::string(argv[i]);
        // If prefix
        if (input.at(0) == '-'){
            current_prefix = input;
        }
        // If argument
        else if (!input.empty()){
            // Reduce input counter
            input_counter--;
            // Specifies document folder
            if (current_prefix == "-d") {
                std::string cwd = std::filesystem::current_path().string();
                // Add directory separator if needed
                if (cwd.back() != '/' && cwd.back() != '\\') {
                    cwd += "/";
                }
                folder_path = cwd + input;
            }
            else if(current_prefix.compare("-s") == 0){
                ngram_size = std::stoi(input);
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
            input.erase();
        }
        i++;
    }
    // Error
    if (input_counter > 1){
        return 0;
    }
    // All inputs entered
    return 1;
}

/**
 * @brief Prints setup
 */
void print_setup(void){
    std::cout << "Document path = " << folder_path << std::endl;
    std::cout << "nGram size = " << ngram_size << std::endl;
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