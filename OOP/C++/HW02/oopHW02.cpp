#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iterator>
#include <cstddef>
using namespace std;

int loader(fstream &fp, string &fname)
{
    fp.open(fname.c_str(), ios::in);
    if (!fp)
    {
        cout << "ERROR : Error reading from file" << endl;
    }
    else
    {
        cout << "Load file " << fname << " successful" << endl;
    }
    return 0;
}

int locater(fstream &fp, string &target, int num)
{
    vector<string> word;
    string line;
    string delimiter("0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ '");
    size_t index = 0;
    int n = 0;

    while (getline(fp, line))
    {
        index = 0;
        while ((index = line.find_first_not_of(delimiter, index)) != string::npos)
        {
            line.replace(index, 1, " ");
            //   cout << "index:" << index << endl;
        }
        word.clear();
        stringstream load(line);
        // cout << load.str() << endl;
        word.assign(istream_iterator<string>(load), istream_iterator<string>());
        for (int i = 0; i < word.size(); i++)
        {
            n++;

            if (target == word[i])
            {
                num--;
            }
            if (num == 0)
            {
                cout << n << endl;
                return 0;
            }
        }
        // cout << "word:" << n << endl;
    }
    cout << "No matching entry" << endl;
    return 0;
}

int main()
{
    vector<string> arr;
    fstream fp;
    string input;
    string token;
    stringstream convert_stoi;
    int n = 0;
    int i = 0;
    int num = 0;
    int openflag = 0;
    char arr2[300];

    while (1)
    {
        n = 0;
        arr.clear();

        cout << ">";
        getline(cin, input);
        stringstream delim(input);
        while (getline(delim, token, ' '))
        {
            arr.push_back(token);
            n++;
        }
        //  cout << "n=" << n << endl;

        if (arr[0] == "load" && n == 2) //load entry
        {
            loader(fp, arr[1]);
            openflag = 1;
        }
        else if (arr[0] == "locate" && n == 3) //locate entry
        {
            if (openflag == 0)
            {
                cout << "No matching entry" << endl;
            }
            else if (openflag == 1)
            {
                for (i = 0; i < arr[2].length(); i++)
                {
                    if (arr[2].at(i) <= '0' || arr[2].at(i) >= '9')
                    {
                        cout << "ERROR: Invalid command" << endl;
                        goto cnt;
                    }
                }
                convert_stoi.str("");
                convert_stoi.clear();
                convert_stoi << arr[2];
                convert_stoi >> num;
                // cout << "num=" << num << endl;
                fp.clear();
                fp.seekg(0);
                locater(fp, arr[1], num);
            }
        }
        else if (arr[0] == "end" && n == 1) //end entry
        {
            exit(1);
        }
        else if (arr[0] == "new" && n == 1) //new entry
        {
            fp.close();
            openflag = 0;
        }
        else
        {
            cout << "ERROR: Invalid command" << endl;
        }
    cnt:;
    } //while
    fp.close();
    return 0;
} //main
