// Main Program Example for HW6

// You can use this file as your main program, or add more functions if you want.
// Please ***MAKE SURE*** that your class works fine in this main program.
// TA will test your class by this program with additional test data.

#include <iostream>
#include <string>
#include "HuffmanTree.h"

using std::cout;
using std::endl;
using std::string;

int main()
{
    // Build a Huffman Tree according to the string
    HuffmanTree t("Abcdaaaabbbbaaaacceee!@&$()#@%*");

    // encode a string
    cout << t.encode("Abcdaaaabbbbaaaacc") << endl;
    cout << t.decode(t.encode("Abcdaaaabbbbaaaacc")) << endl;

    // The Hoffman Tree t will be unable to encode this
    // Therefore, please print out error message and return an empty string("") when encounter this.
    cout << t.encode("Abcdaaaeeeabbbbaaaac@@@%%cRRRRR") << endl;

    // decode a string
    cout << t.decode("101011110000111100101111111010111") << endl;

    // The Hoffman Tree t will be unable to decode this
    // Therefore, please print out error message and return an empty string("") when encounter this.
    cout << t.decode("1010111100001111001011111110101111") << endl;
    HuffmanTree D("aaaeeeabbbb");
    cout << D.encode("aae") << endl;
    cout << D.encode("SSSDDDDDDDDDDD") << endl;
    cout << "decode" << endl;
    cout << D.decode("10101111000011110010461111111010111") << endl;

    cout << "one" << endl;
    HuffmanTree one("D");
    cerr << one.encode("DDDDDDDD") << endl;
    cout << one.encode("SSSDDDssadDDDDDDDD") << endl;
    cout << one.decode("0080461111111010111") << endl;

    cout << "two" << endl;
    HuffmanTree two("AB");
    cerr << two.encode("AAABBB") << endl;
    cout << two.encode("SSSABBBDDDDD") << endl;
    cout << two.decode("001111111010111") << endl;

    cout << "zero" << endl;
    HuffmanTree Z("");
    cerr << Z.encode("DDDDDDDD") << endl;
    cout << Z.encode("SSSDDDssadDDDDDDDD") << endl;
    cout << Z.decode("0080461111111010111") << endl;

    cout << "story" << endl;
    HuffmanTree story("Later that Day, when the Princess was sitting at the table, something was heard coming up the marble stairs. Splish, splosh, splish splosh! The sound came nearer and nearer, and a voice cried, Let me in, youngest daughter of the King.The Princess jumped up to see who had called her. Now when she caught sight of the frog, she turned very pale.What does a frog want with you? demanded the King, looking rather surprised.The Princess hung her head. When I was sitting by the fountain my golden ball fell into the water. This frog fetched it back for me, because I cried so much. The Princess started to cry again. I promised to love him and let him eat from my golden plate, drink from my golden cup, and sleep on my golden bed.The King looked at the frog and thought for a while before he spoke. Then you must keep your promise, my daughter.The Princess knew she must obey, so she let the frog to come inside. The frog hopped in after her and jumped up into her chair and straight onto the table. Now push your golden plate near me. said the frog, so that we may eat together. As she did so, the frog leapt onto her plate and ate up all her dinner, which was just as well, because the Princess didn't feel much like eating.Next, the frog drank from her little golden cup until it was quite empty. Somehow the Princess didnt feel at all thirsty either! After the frog had finished, he took one great leap and landed on the Princesss knee.Go away you ugly, cold frog! she screamed. I will never let you sleep on my lovely, clean bed!That made the King very angry. This frog helped you when you needed it. Now you must keep your promise to him.Very unwillingly the Princess picked up the frog and carried him upstairs to her room. When the frog hopped into the middle of her golden bed, it was just too much for the Princess. She pushed the frog hard and it fell onto the floor. As he fell he was changed into a handsome Prince. A spell had been cast on him by an evil witch and only the Princess had the power to break it.The Princess was speechless. She felt very sorry indeed that she had been so unkind to the frog. After a while, the handsome Prince and the Princess were married, and lived happily ever after.");
    cerr << story.encode("DDDDDDDD") << endl; //D only on: Later that "D"ay,
    cout << story.encode("fdsgadsdeweeeeeeeefdffw") << endl;
    cout << story.decode("001111111010111") << endl;
    cout << story.decode(story.encode("Later that Day, when the Princess was sitting at the table, something was heard coming u")) << endl;
    return 0;
}