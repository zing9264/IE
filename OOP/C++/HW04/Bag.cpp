#ifndef BAG_CPP
#define BAG_CPP
#include "Bag.h"
template <class ItemType>
Node<ItemType>::Node(ItemType v)
{
    value = v;
    previous = NULL;
    next = NULL;
    cerr << "node constructed" << endl;
}

template <class ItemType>
Node<ItemType>::Node()
{

    previous = NULL;
    next = NULL;
    cerr << "dummy node constructed" << endl;
}

template <class ItemType>
Node<ItemType>::~Node()
{
    cerr << "node destructed" << endl;
}

//----------------
template <typename ItemType>
Bag<ItemType>::Bag()
{

    isinit = false;
    numberOfItem = 0;
    fingerCount = 0;
    obj_b = new ItemType;
    memset(obj_b, '\0', sizeof(obj_b));
    root = new Node<ItemType>();
    root->previous = root;
    root->next = root;
    tail = root;
    finger = root;
    cerr << "Bag constructed" << endl;
}

template <typename ItemType>
bool Bag<ItemType>::empty() const
{

    if (numberOfItem == 0)
    {
        return true;
    }
    else
        return false;
}

//回傳背包中物品總數
template <typename ItemType>
int Bag<ItemType>::size() const
{

    return numberOfItem;
}

template <typename ItemType>
int Bag<ItemType>::uniqueSize() const
{
    ItemType *uniArr = new ItemType[200];
    memset(uniArr, '\0', sizeof(uniArr));
    int uniItem = 0;
    const Node<ItemType> *ptr = root;
    int flag = 0;
    for (int i = 0; i < numberOfItem; i++)
    {
        flag = 0;
        ptr = ptr->next;
        for (int j = 0; j <= uniItem; j++)
        {
            if (ptr->value == uniArr[j])
            {
                flag = 1;
            }
        }
        if (flag == 0)
        {
            uniArr[uniItem] = ptr->value;
            ++uniItem;
        }
    }
    delete[] uniArr;
    return uniItem;
}

template <typename ItemType>
bool Bag<ItemType>::insert(const ItemType &value)
{
    Node<ItemType> *Pnode;
    Pnode = new Node<ItemType>(value);
    Pnode->previous = tail;
    Pnode->next = root;
    root->previous = Pnode;
    tail->next = Pnode;
    tail = tail->next;
    isinit = false;
    ++numberOfItem;
    return true;
}

template <typename ItemType>
int Bag<ItemType>::erase(const ItemType &value)
{
    isinit = false;
    Node<ItemType> *ptr = root->next;
    int cnt = 0;
    for (int i = 1; i <= numberOfItem; i++)
    {
        if (ptr->value == value)
        {
            cnt = i;
            ptr->previous->next = ptr->next;
            ptr->next->previous = ptr->previous;
            delete ptr;
            --numberOfItem;
            break;
        }
        ptr = ptr->next;
    }

    return cnt;
}
template <typename ItemType>
int Bag<ItemType>::eraseAll(const ItemType &value)
{
    isinit = false;
    Node<ItemType> *ptr = root->next;
    Node<ItemType> *tmp;
    int cnt = 0;
    for (int i = 1; i <= numberOfItem; i++)
    {
        tmp = ptr;
        ptr = ptr->next;
        if (tmp->value == value)
        {
            cnt++;
            tmp->previous->next = tmp->next;
            tmp->next->previous = tmp->previous;
            delete tmp;
        }
    }
    numberOfItem -= cnt;
    return cnt;
}
template <typename ItemType>
bool Bag<ItemType>::contains(const ItemType &value) const
{
    const Node<ItemType> *ptr = root->next;
    for (int i = 1; i <= numberOfItem; i++)
    {
        if (ptr->value == value)
        {
            return true;
        }
        ptr = ptr->next;
    }
    return false;
}

template <typename ItemType>
int Bag<ItemType>::count(const ItemType &value) const
{
    const Node<ItemType> *ptr = root->next;
    int cnt = 0;
    for (int i = 1; i <= numberOfItem; i++)
    {
        if (ptr->value == value)
        {
            ++cnt;
        }
        ptr = ptr->next;
    }
    return cnt;
}

//----------------------------------------------------------------traversal-------------------------------------

//初始化手指，將手指指到第一個物品,若包包為空，印Please input item，並且程式不能壞掉
template <typename ItemType>
void Bag<ItemType>::start()
{
    finger = root->next;
    fingerCount = 1;
    isinit = true;
    if (numberOfItem == 0)
    {
        cerr << "Please input item" << endl;
        isinit = false;
        fingerCount = 0;
    }
    return;
}

//將手指指到下一個物品,若更動過背包中的物品(insert, erase, eraseAll)，必須先初始化才能使用呼叫next(),
//<--若還未將手指初始化就呼叫next()，印Please initializes，並且程式不能壞掉,若已經走訪完畢，讓手指不再指向任何物品
template <typename ItemType>
void Bag<ItemType>::next()
{
    if (isinit == false)
    {
        cerr << "Please initializes" << endl;
        return;
    }
    else if (finger->next == root)
    {
        finger = NULL;
        fingerCount = 0;
        isinit = false;
    }
    else
    {
        finger = finger->next;
        ++fingerCount;
    }
    return;
}

//如果手指沒有指向任何物品就回傳true，否則回傳false
template <typename ItemType>
bool Bag<ItemType>::ended() const
{
    if (finger == NULL || finger == root)
    {
        return true;
    }
    else
        return false;
}

//回傳手指指到的物品
//若更動過背包中的物品(insert, erase, eraseAll)，必須先初始化才能使用呼叫currentValue()
//若還未將手指初始化就呼叫currentValue()，印Please initializes，並且程式不能壞掉
template <typename ItemType>
const ItemType &Bag<ItemType>::currentValue() const
{

    if (finger == NULL || finger == root)
    {
        cerr << "Please initializes" << endl;
        return *obj_b;
    }
    else
        return finger->value;
}

//回傳手指指到的是第幾個物品,若更動過背包中的物品(insert, erase, eraseAll)，必須先初始化才能使用呼叫currentCount()
//若還未將手指初始化就呼叫currentCount，印Please initializes，回傳0，並且程式不能壞掉
template <typename ItemType>
int Bag<ItemType>::currentCount() const
{
    if (finger == NULL || finger == root)
    {
        cerr << "Please initializes" << endl;
        return 0;
    }
    return fingerCount;
}

//----------------------bag copy / assign operator------------------------

template <typename ItemType>
Bag<ItemType>::Bag(const Bag<ItemType> &A)
{
    Node<ItemType> *pn = A.root;
    isinit = false;
    numberOfItem = 0;
    fingerCount = 0;

    root = new Node<ItemType>();
    root->previous = root;
    root->next = root;
    tail = root;
    finger = root;
    obj_b = new ItemType;
    memset(obj_b, '\0', sizeof(obj_b));
    //copy value
    for (int i = 0; i < A.size(); i++)
    {
        insert(pn->next->value);
        pn = pn->next;
    }

    cerr << "Bag copy constructor" << endl;
}
template <typename ItemType>
Bag<ItemType> &Bag<ItemType>::operator=(const Bag<ItemType> &A)
{
    int i = 0;
    Node<ItemType> *ptr = root->next;
    root = new Node<ItemType>();
    Node<ItemType> *tmp;
    for (i = 1; i <= numberOfItem; i++)
    {
        tmp = ptr;
        ptr = ptr->next;
        tmp->previous->next = tmp->next;
        tmp->next->previous = tmp->previous;
        delete tmp;
    }
    delete obj_b;
    delete ptr;
    Node<ItemType> *pn = A.root;
    isinit = false;
    numberOfItem = 0;
    fingerCount = 0;
    root->previous = root;
    root->next = root;
    tail = root;
    finger = root;
    obj_b = new ItemType;
    memset(obj_b, '\0', sizeof(obj_b));
    //copy value
    for (int i = 0; i < A.size(); i++)
    {
        insert(pn->next->value);
        pn = pn->next;
    }
    cerr << "Bag assignment operator" << endl;
    return *this;
}

template <typename ItemType>
Bag<ItemType>::~Bag()
{
    int i = 0;
    Node<ItemType> *ptr = root->next;
    Node<ItemType> *tmp;
    for (i = 1; i <= numberOfItem; i++)
    {
        tmp = ptr;
        ptr = ptr->next;
        tmp->previous->next = tmp->next;
        tmp->next->previous = tmp->previous;
        delete tmp;
    }
    delete root;
    delete obj_b;
    cerr << "Bag destructed" << endl;
}

//------------------non member function-----------------
//result中有bag1和bag2中的所有東西，bag1和bag2原有的物品不能有任何改變在這裡就不規定result順序，只要result內物品數量都正確即可

template <typename ItemType>
void combine(Bag<ItemType> &bag1, Bag<ItemType> &bag2, Bag<ItemType> &result)
{
    result = bag1;
    bag2.start();
    for (int i = 0; i < bag2.size(); i++)
    {
        result.insert(bag2.currentValue());
        bag2.next();
    }
}

//假設bag1中有n1個"duck", bag2中有n2個"duck",如果n1>n2,
//則result中有n1-n2個"duck"，如果n1<=n2,則result沒有"duck"
//在這裡就不規定result順序，只要result內物品數量都正確即可
template <typename ItemType>
void subtract(Bag<ItemType> &bag1, Bag<ItemType> &bag2, Bag<ItemType> &result)
{
    result = bag1;
    bag2.start();
    for (int i = 0; i < bag2.size(); i++)
    {
        result.erase(bag2.currentValue());
        bag2.next();
    }
}

#endif