#include "HuffmanTree.h"

int Node::getFreq()
{
    return this->freq;
}

int InternalNode::getNodeType() // 0: terminal node 1: internal node
{
    return 1;
}
Node *InternalNode::getLChild()
{
    return this->lChild;
}
Node *InternalNode::getRChild()
{
    return this->rChild;
}
char InternalNode::getValue() // internal node 沒有 value，因此請印出提示訊息，並且 return 0。
{
    cout << "Error:internal node 沒有 value" << endl;
    return 0;
}

int TerminalNode::getNodeType() // 0: terminal node 1: internal node
{
    return 0;
}
Node *TerminalNode::getLChild() // terminal node 沒有 LChild，因此請印出提示訊息，並且 return NULL。
{
    cout << "Error:terminal node 沒有 LChild" << endl;
    return NULL;
}

Node *TerminalNode::getRChild() // terminal node 沒有 RChild。
{
    cout << "Error:terminal node 沒有 RChild" << endl;
    return NULL;
}
char TerminalNode::getValue()
{
    return this->value;
}

HuffmanTree::HuffmanTree(const string &s)
{
    int i = 0;

    int c[127];
    memset(c, 0, sizeof(c));

    for (i = 0; i < s.size(); i++)
    {
        c[(int)s[i]]++;
    }
    j = 0;
    for (i = 32; i < 127; i++)
    {
    }
}