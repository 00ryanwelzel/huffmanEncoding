#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include "huffmanNode.h"

#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;


class huffmanTree
{
    private:
        unordered_map<char, int>& frequencies;
        unordered_map<char, string>& codes;
    public:
        huffmanTree(unordered_map<char, int>&, unordered_map<char, string>&);
        
        void buildTree(const string&);
        void generateCodes(huffmanNode*, const string&);

        void printCodes();
        void printEncoded(const string&);
};


#endif