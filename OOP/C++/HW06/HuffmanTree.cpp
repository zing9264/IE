#include "HuffmanTree.h"

Node *maketree(Node *head, int i);
//void traversal(Node *p);
void DELtraversal(Node *p);

Node::Node()
{
    freq = 0;
}

Node::Node(int i)
{
    freq = i;
}
Node::~Node()
{
}
int Node::getFreq()
{
    return this->freq;
}
InternalNode::InternalNode() : Node()
{
    lChild = NULL;
    rChild = NULL;
}

InternalNode::InternalNode(int i, Node *lptr, Node *rptr) : Node(i), lChild(lptr), rChild(rptr)
{
    //cout << "InternalNode insert :" << i << endl;
}
InternalNode::~InternalNode()
{
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

TerminalNode::TerminalNode() : Node()
{
    value = '\0';
}

TerminalNode::TerminalNode(int i, char c) : Node(i)
{
    value = c;
}
TerminalNode::~TerminalNode()
{
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
    Node *nptr = NULL;
    Node *last = NULL;
    Node *head = NULL;
    int i = 0;
    int nodecnt = 0;
    int c[127];
    memset(c, 0, sizeof(c));

    for (i = 0; i < s.size(); i++)
    {
        c[(int)s[i]]++;
    }
    for (i = 32; i < 127; i++)
    {
        if (c[i] != 0)
        {
            nptr = new TerminalNode(c[i], (char)i);
            nodecnt++;
            if (last != NULL)
            {
                last->next = nptr;
            }
            else
            {
                head = nptr;
            }
            last = nptr;
        }
    }
    nptr = head;
    while (nptr)
    {
        cout << "node---" << nptr->getValue() << "  " << nptr->getFreq() << endl;
        nptr = nptr->next;
    }
    root = maketree(head, nodecnt);
    //  traversal(root);
}
HuffmanTree::~HuffmanTree()
{
    DELtraversal(root);
}

Node *maketree(Node *head, int nodecnt)
{
    Node *root;
    if (nodecnt == 1)
    {
        return head;
    }

    Node *Lchild = NULL;
    Node *Llast = head;
    Node *Rchild = NULL;
    Node *Rlast = head;
    Node *tmp = NULL;
    Node *last = head;
    Node *ptr = head;
    int minL = 2147483647;
    int minR = 2147483647;

    while (ptr)
    {
        if (ptr->getFreq() < minL)
        {
            Llast = last;
            Lchild = ptr;
            minL = ptr->getFreq();
        }
        last = ptr;
        ptr = ptr->next;
    }
    // //cerr << "left--" << Lchild->getValue() << Lchild->getFreq() << endl;
    Llast->next = Lchild->next;
    if (Lchild == head)
    {
        head = head->next;
    }

    ptr = head;
    last = head;

    while (ptr)
    {
        if (ptr->getFreq() < minR && ptr != Lchild)
        {
            Rlast = last;
            Rchild = ptr;
            minR = ptr->getFreq();
        }
        last = ptr;
        ptr = ptr->next;
    }
    //cerr << "right--" << Rchild->getValue() << Rchild->getFreq() << endl;
    Rlast->next = Rchild->next;
    //cerr << "isnull?";
    if (nodecnt == 2)
    {
        if (minR > minL)
        {
            tmp = Rchild;
            Rchild = Lchild;
            Lchild = tmp;
        }
        root = new InternalNode(Lchild->getFreq() + Rchild->getFreq(), Lchild, Rchild);
        return root;
    }
    if (Rchild == head)
    {
        head = head->next;
    }
    //cerr << "head--" << head->getValue() << head->getFreq() << endl;
    if (minR > minL)
    {
        tmp = Rchild;
        Rchild = Lchild;
        Lchild = tmp;
    }
    //cerr << "root" << endl;
    root = new InternalNode(Lchild->getFreq() + Rchild->getFreq(), Lchild, Rchild);
    root->next = head;
    head = root;

    //cerr << "return" << nodecnt << endl;
    return root = maketree(head, nodecnt - 1);
}

void DELtraversal(Node *p)
{
    if (!p)
        return;
    DELtraversal(p->getLChild());
    cout << "node--- " << p->getValue() << "  " << p->getFreq() << endl; // 挪到中間，改變輸出順序。
    DELtraversal(p->getRChild());
    delete p;
}