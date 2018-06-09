#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class Node
{

protected:
  int freq; // 儲存 terminal node 的字頻，或 internal node 所有子節點的字頻總和。
public:
  Node();
  Node(int i);
  virtual ~Node();
  int getFreq();
  virtual int getNodeType() = 0; // 0: terminal node 1: internal node
  virtual char getValue() = 0;
  virtual Node *getLChild() = 0;
  virtual Node *getRChild() = 0;
  Node *next;
  Node *charnext;
};

//InternalNode 包含以下內容:
class InternalNode : public Node
{
private:
  Node *lChild; // left child
  Node *rChild; // right child
public:
  InternalNode();
  InternalNode(int i, Node *lptr, Node *rptr);
  ~InternalNode();
  int getNodeType(); // 0: terminal node 1: internal node
  Node *getLChild();
  Node *getRChild();
  char getValue(); // internal node 沒有 value，因此請印出提示訊息，並且 return 0。
};

//TerminalNode 包含以下內容:
class TerminalNode : public Node
{
private:
  char value; // 儲存這個 node 代表的字元
public:
  TerminalNode();
  TerminalNode(int i, char c);
  ~TerminalNode();
  int getNodeType(); // 0: terminal node 1: internal node
  Node *getLChild(); // terminal node 沒有 LChild，因此請印出提示訊息，並且 return NULL。
  Node *getRChild(); // terminal node 沒有 RChild。
  char getValue();
};

class HuffmanTree
{

public:
  HuffmanTree(const string &s);
  /*可以接受一個字串(string)，計算這個字串的各個字元(char)的頻率(即同一個字元的總數)，
    生成對應的 Huffman 編碼樹。 
    輸入字串包含 ASCII 表上 32(空白) 到 126(~) 為止的所有符號，
    包含英文字母(有區分大小寫)、空白及逗號、括號等符號。
    提示: 你可以把字串中所有的字元的頻率(出現次數) 計算出來，
    並且用 recursive(遞迴) 的方式，由下而上建立整個 Huffman Tree。
    如果要用 iterative 的方式也可以接受。(但實作上應該會比較複雜一點)
    */
  ~HuffmanTree();
  /*請確保所有的內容(以及子節點)
    的內容都有刪乾淨。 助教會以 Valgrind 測試是否有 memory leak(此項測試佔 7 分)
    */
  string encode(const string &s) const;
  /*  以目前的 Huffman Tree 的結構，把一個字串編碼成 001010101100... ，並以 string 的形式輸出。 (如果你要用 array of bool，vector<bool> 或 deque<bool> 等結構也可以，但請在 readme 註明)
    當出現無法編碼的字元時(例如， HuffmanTree t 只利用 a, b, c, d 四個字元建立，encode 輸入的字串卻有 e 時)
    ，必須印出提示訊息(例如 error: character e cannot be encoded) ，並回傳空字串。
*/
  string decode(const string &s) const;
  /*  把經由 Huffman Tree 編碼成 001010101100... 的訊息解碼成原本的字串。 無法成功解碼時，必須印出提示訊息(例如 error: sequence 1011010 cannot be decoded) ，並回傳空字串。
    (提示: 你可以選擇把整個 Huffman Tree 走訪(traverse) 一次，再把結果儲存在一個表上，用來查詢，
   這樣實作起來應該會比較容易。)*/

private:
  Node *root;
  Node *charhead;
};