#include "HuffmanTree.h"
#include <stack>
#include <queue>

Node *maketree(Node *head, int i);
//void traversal(Node *p);
void DELtraversal(Node *p);

void findvalue(stack<string> &cstake, Node *p, char c, int *isdo);

Node::Node()
{
    next = NULL;
    charnext = NULL;
    freq = 0;
}

Node::Node(int i)
{
    next = NULL;
    charnext = NULL;
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
    next = NULL;
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
    charhead = NULL;
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
                last->charnext = nptr;
            }
            else
            {
                head = nptr;
            }
            last = nptr;
        }
    }
    nptr = head;
    charhead = head;

    while (nptr)
    {
        // cout << "node---" << nptr->getValue() << "  " << nptr->getFreq() << endl;
        nptr = nptr->next;
    }
    root = maketree(head, nodecnt);
}
HuffmanTree::~HuffmanTree()
{
    DELtraversal(root);
}

string HuffmanTree::encode(const string &s) const
{

    stack<string> cstake;
    stack<string> revstake;
    queue<char> errq;
    string output;
    bool isin;
    int isdo = 1;
    int i = 0;
    isdo = 1;
    Node *ptr;
    ptr = charhead;
    for (i = 0; i < s.size(); i++)
    {

        ptr = charhead;
        isin = 0;
        while (ptr)
        {

            if (ptr->getValue() == s[i])
            {
                isin = 1;
            }
            ptr = ptr->charnext;
        }
        if (isin == 0)
        {
            isdo = 0;
            errq.push(s[i]);
        }
    }
    if (isdo == 0)
    {
        cerr << "error: character ";
        while (!errq.empty())
        {
            cerr << " " << errq.front();
            errq.pop();
        }

        cerr << " cannot be encoded.";
        return "\0";
    }

    for (i = 0; i < s.size(); i++)
    {
        isdo = 1;
        findvalue(cstake, root, s[i], &isdo);
        // cstake.push("'");
    }
    while (!cstake.empty())
    {
        revstake.push(cstake.top());
        cstake.pop();
    }
    while (!revstake.empty())
    {
        output += revstake.top();
        revstake.pop();
    }
    return output;
}

string HuffmanTree::decode(const string &s) const
{
    queue<char> outque;
    string output;
    Node *nptr;
    int i;
    bool checknull; //1=there is a path to null  ---   0=no null
    nptr = root;
    checknull = 0;
    for (i = 0; i < s.size(); i++)
    {

        if (nptr->getNodeType() == 0 && checknull == 0)
        {
            output += nptr->getValue();
            nptr = root;
            while (!outque.empty())
            {
                outque.pop();
            }
        }
        outque.push(s[i]);
        if (checknull == 0)
        {
            if (s[i] == '0')
            {
                if (nptr->getLChild() != NULL)
                    nptr = nptr->getLChild();
                else
                {
                    checknull = 1;
                }
            }
            else if (s[i] == '1')
            {
                if (nptr->getRChild() != NULL)
                    nptr = nptr->getRChild();
                else
                {
                    checknull = 1;
                }
            }
            else
            {
                checknull = 1;
            }
        }
    }

    if (nptr->getNodeType() == 0 && checknull == 0)
    {
        output += nptr->getValue();
        nptr = root;
        while (!outque.empty())
        {
            outque.pop();
        }
    }
    if (!outque.empty())
    {
        cerr << "error: sequence ";
        while (!outque.empty())
        {
            cerr << outque.front();
            outque.pop();
        }
        cerr << " cannot be decoded";
        return "\0";
    }
    return output;
}
Node *maketree(Node *head, int nodecnt)
{
    Node *root;
    Node *Lchild = NULL;
    Node *Llast = head;
    Node *Rchild = NULL;
    Node *Rlast = head;
    Node *tmp = NULL;
    Node *last = head;
    Node *ptr = head;
    int minL = 2147483647;
    int minR = 2147483647;
    if (nodecnt == 0)
    {
        return root = new InternalNode(0, NULL, NULL);
    }

    if (nodecnt == 1)
    {
        return root = new InternalNode(ptr->getFreq(), ptr, NULL);
    }

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
    if (p->getNodeType() == 1)
    {
        DELtraversal(p->getLChild());
        DELtraversal(p->getRChild());
    }
    else
    {
        DELtraversal(NULL);
    }
    delete p;
}
void findvalue(stack<string> &cstake, Node *p, char c, int *isdo)
{
    if (*isdo == 0)
    {
        return;
    }

    if (p->getNodeType() == 0)
    {
        if (p->getValue() == c)
        {
            *isdo = 0;
            return;
        }
        return;
    }

    if (p->getNodeType() != 0)
    {
        cstake.push("0");
        findvalue(cstake, p->getLChild(), c, isdo);
        if (*isdo != 0)
        {
            cstake.pop();
        }
        if (*isdo == 0)
        {
            return;
        }
        cstake.push("1");
        findvalue(cstake, p->getRChild(), c, isdo);
        if (*isdo != 0)
        {
            cstake.pop();
        }
    }
}
