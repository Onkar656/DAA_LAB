#include <bits/stdc++.h>
using namespace std;

struct HuffmanNode
{
    string name;
    int frequency;
    HuffmanNode *left;
    HuffmanNode *right;

    HuffmanNode(string name, int frequency)
    {
        this->name = name;
        this->frequency = frequency;
        left = right = nullptr;
    }

    bool isLeaf()
    {
        return left == nullptr && right == nullptr;
    }
};

struct CompareNodes
{
    bool operator()(HuffmanNode *a, HuffmanNode *b)
    {
        return a->frequency > b->frequency;
    }
};

void printHuffmanTree(HuffmanNode *root, string code = "")
{
    if (root == nullptr)
    {
        return;
    }

    if (root->isLeaf())
    {
        cout << "Character: " << root->name << ", Frequency: " << root->frequency << ", Code: " << code << endl;
    }
    else
    {
        cout << "Node: " << root->name << ", Frequency: " << root->frequency << endl;
    }

    printHuffmanTree(root->left, code + "0");
    printHuffmanTree(root->right, code + "1");
}

HuffmanNode *buildHuffmanTree(map<char, int> &frequencyTable)
{
    priority_queue<HuffmanNode *, vector<HuffmanNode *>, CompareNodes> pq;
    char nodeName = 'A'; // Naming internal nodes starting from 'A'

    for (const auto &pair : frequencyTable)
    {
        pq.push(new HuffmanNode(string(1, pair.first), pair.second));
    }

    while (pq.size() > 1)
    {
        HuffmanNode *left = pq.top();
        pq.pop();
        HuffmanNode *right = pq.top();
        pq.pop();

        string newNodeName = "Node" + string(1, nodeName++);
        HuffmanNode *newNode = new HuffmanNode(newNodeName, left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;
        pq.push(newNode);

        cout << "Merged: " << left->name << " and " << right->name << " to create " << newNode->name << " with frequency: " << newNode->frequency << endl;
    }

    return pq.top();
}

void generateHuffmanCodes(HuffmanNode *root, string code, map<char, string> &huffmanCodes)
{
    if (root == nullptr)
    {
        return;
    }

    if (root->isLeaf())
    {
        huffmanCodes[root->name[0]] = code;
    }

    generateHuffmanCodes(root->left, code + "0", huffmanCodes);
    generateHuffmanCodes(root->right, code + "1", huffmanCodes);
}

int main()
{
    map<char, int> frequencyTable;
    map<char, string> huffmanCodes;

    int numCharacters;
    cout << "Enter the number of characters: ";
    cin >> numCharacters;
    for (int i = 0; i < numCharacters; i++)
    {
        char character;
        int frequency;
        cout << "Enter character " << i + 1 << ": ";
        cin >> character;
        cout << "Enter frequency for character " << character << ": ";
        cin >> frequency;
        frequencyTable[character] = frequency;
    }

    HuffmanNode *root = buildHuffmanTree(frequencyTable);

    cout << "Huffman Tree:" << endl;
    printHuffmanTree(root);

    generateHuffmanCodes(root, "", huffmanCodes);

    cout << "Huffman Codes:" << endl;
    int totalBitsRequired = 0;
    for (const auto &pair : huffmanCodes)
    {
        totalBitsRequired += pair.second.length() * frequencyTable[pair.first];
        cout << pair.first << ": " << pair.second << endl;
    }

    cout << "Total bits required to store: " << totalBitsRequired << " bits." << endl;

    return 0;
}
