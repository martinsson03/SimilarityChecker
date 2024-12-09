#include <array>
#include <string>

using namespace std;

struct Ngram{
    std::array<string, 5> words;
};

struct Node{
    int key;
    int value;
    int height;
    int size;
    Node* left_child;
    Node* right_child;
};