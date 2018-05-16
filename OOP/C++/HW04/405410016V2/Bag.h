#ifndef BAG_H
#define BAG_H
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

template <class ItemType>
class Node
{
public:
  Node(ItemType v);
  Node();
  ~Node();
  Node<ItemType> *previous;
  Node<ItemType> *next;
  ItemType value;
};

template <class ItemType>
class Bag
{
public:
  Bag();  //印出Bag constructed建立一個空的背包
  ~Bag(); //印出Bag destructed
  Bag(const Bag<ItemType> &);

  bool empty() const;                         //如果背包是空的就回傳true，否則回傳false
  int size() const;                           //回傳背包中物品總數
  int uniqueSize() const;                     //回傳背包中相異物品數
  bool insert(const ItemType &value);         //將一個物品value加入背包中，成功加入便回傳true
  int erase(const ItemType &value);           //移除背包中一個物品value，回傳移除的是第幾個物品，若背包中沒這樣物品則回傳0
  int eraseAll(const ItemType &value);        //移除所有物品value，回傳移除的數量
  bool contains(const ItemType &value) const; //如果背包中包含物品value就回傳true，否則回傳false
  int count(const ItemType &value) const;     //回傳物品value在背包中的數量
  //-------------------traversal-----------------------------------------------------------------------------
  void start();                         //初始化手指，將手指指到第一個物品,若包包為空，印Please input item，並且程式不能壞掉
  void next();                          //將手指指到下一個物品,若更動過背包中的物品(insert, erase, eraseAll)，必須先初始化才能使用呼叫next(),
                                        //<--若還未將手指初始化就呼叫next()，印Please initializes，並且程式不能壞掉,若已經走訪完畢，讓手指不再指向任何物品
  bool ended() const;                   //如果手指沒有指向任何物品就回傳true，否則回傳false
  const ItemType &currentValue() const; //回傳手指指到的物品,若更動過背包中的物品(insert, erase, eraseAll)，必須先初始化才能使用呼叫currentValue()
  //若還未將手指初始化就呼叫currentValue()，印Please initializes，並且程式不能壞掉
  int currentCount() const; //回傳手指指到的是第幾個物品,若更動過背包中的物品(insert, erase, eraseAll)，必須先初始化才能使用呼叫currentCount()
  //若還未將手指初始化就呼叫currentCount，印Please initializes，回傳0，並且程式不能壞掉
  //-----------------------operator overloading---------------
  Bag &operator=(const Bag<ItemType> &);

private:
  bool isinit;
  int numberOfItem;
  int fingerCount;
  ItemType *obj_b;
  Node<ItemType> *root; //dummy_node;
  Node<ItemType> *tail;
  Node<ItemType> *finger;
};

#endif
