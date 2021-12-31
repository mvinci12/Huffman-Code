#pragma once
#ifndef Huffman_h
#define Huffman_h

#include<iostream>
#include<queue>
#include<string>
#include<fstream>
using namespace std;

class Huffman 
{
    struct node {

        char data;
        int frequency;
        node* left, *right;

        node(char data, unsigned frequency)
        {
            left = right = NULL;
            this->data = data;
            this->frequency = frequency;
        }
    };

    struct compare {

        bool operator()(node* left, node* right)

        {
            return (left->frequency > right->frequency);
        }
    };

    priority_queue<node*, vector<node*>, compare> minHeap;

    void printHuffmanCodes(node* root, string str);

public:

    void buildHuffmanTree(char characters[], int frequency[], int size);
    void printCodes();
    void decodeText(string filename);
};
#endif