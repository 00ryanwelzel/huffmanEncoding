#include "huffmanNode.h"
#include "huffmanTree.h"

using namespace std;


int main(){
    unordered_map<char, int> frequencies;
    unordered_map<char, string> codes;

    string input = "";
    string temp;

    while(!std::cin.eof()){
        std::cin >> temp;
        input += temp;
    }

    huffmanTree* h = new huffmanTree(frequencies, codes);

    h->buildTree(input);
    h->printCodes();
    h->printEncoded(input);

    return 0;
}