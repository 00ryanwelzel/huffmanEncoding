#ifndef NODE_H
#define NODE_H

using namespace std;


class huffmanNode{
    private:
    public:
        char c;
        int frequency;

        huffmanNode* left;
        huffmanNode* right;

        huffmanNode(char, int);
};

#endif