#include "huffmanNode.h"

using namespace std;


huffmanNode::huffmanNode(char c, int frequency){
    this->c = c;
    this->frequency = frequency;

    this->left = nullptr;
    this->right = nullptr;
}