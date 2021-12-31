#include "Huffman.h"

//My partner is Chris Alonzo - calonzo@bu.edu

void Huffman::buildHuffmanTree(char characters[], int frequency[], int size)
{
    node* left, * right, * top;

    for (int i = 0; i < size; ++i)
        this->minHeap.push(new node(characters[i], frequency[i]));

    while (this->minHeap.size() != 1) {

        left = this->minHeap.top();
        this->minHeap.pop();

        right = this->minHeap.top();
        this->minHeap.pop();

        top = new node(NULL, left->frequency + right->frequency);

        top->left = left;
        top->right = right;

        this->minHeap.push(top);
    }
}

void Huffman::printCodes()
{
    cout << "Huffman Code\t   Character" << endl;
    cout << "----------------------------------" << endl;
    this->printHuffmanCodes(this->minHeap.top(), "");
}

void Huffman::decodeText(string filename)
{
    string encodedText;
    ifstream encodedFile(filename);

    getline(encodedFile, encodedText);

    encodedFile.close();

    string decodedText = "";
    struct node* temp = this->minHeap.top();
    for (int i = 0; i < encodedText.size(); i++)
    {
        if (encodedText[i] == '0')
            temp = temp->left;
        else
            temp = temp->right;

        if (temp->left == NULL && temp->right == NULL)
        {
            decodedText += temp->data;
            temp = minHeap.top();
        }
    }

    decodedText += '\0';
    cout << endl << "The decoded text is: " << decodedText;
}

void Huffman::printHuffmanCodes(node* root, string str)
{
    if (!root)
        return;

    if (root->left == NULL && root->right == NULL)
        cout << str << "\t\t\t" << root->data << "\n";

    printHuffmanCodes(root->left, str + "0");
    printHuffmanCodes(root->right, str + "1");
}