#include "huffmanTree.h"
#include "huffmanNode.h"

using namespace std;


huffmanTree::huffmanTree(unordered_map<char, int>& f, unordered_map<char, string>& c) : frequencies(f), codes(c) {}

struct lesserCompare{
    bool operator()(huffmanNode* a, huffmanNode* b) const {
        return a->frequency > b->frequency;
    }
};

void huffmanTree::buildTree(const string& text){
    priority_queue<huffmanNode*, vector<huffmanNode*>, lesserCompare> queue;

    for(char c : text) frequencies[c]++;
    for(auto pair : frequencies) queue.push(new huffmanNode(pair.first, pair.second));

    while(queue.size() > 1){
        huffmanNode* left = queue.top(); queue.pop();
        huffmanNode* right = queue.top(); queue.pop();

        int freqTotal = left->frequency + right->frequency;

        huffmanNode* comboNode = new huffmanNode('\0', freqTotal);
        comboNode->left = left;
        comboNode->right = right;

        queue.push(comboNode);
    }

    huffmanNode* root = queue.top();

    generateCodes(root, "");

    return;
}

void huffmanTree::generateCodes(huffmanNode* root, const string& code){
    if(!root) return;

    if(!root->left && !root->right){
        codes[root->c] = code;
    }

    generateCodes(root->left, code + "0");
    generateCodes(root->right, code + "1");

}

void huffmanTree::printCodes(){
    cout << "All Huffman codes:\n";

    for(auto pair : codes) cout << pair.first << ": " << pair.second << endl;
    return;
}

void huffmanTree::printEncoded(const string& text){
    string encoded = "";

    for(char c : text){
        encoded += codes[c];
    }

    cout << "Encoded string:\n" << encoded << endl;
}