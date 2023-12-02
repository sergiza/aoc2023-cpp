#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "utils.cpp"
using namespace std;

void e1(vector<string> input)
{
    int result = 0;
    int first  = 0;
    int last   = 0;
    bool firstFound = false;
    bool lastFound  = false;

    for(string line : input)
    {
        cout << line << endl;
        for(char chara : line)
        {
            cout << chara << endl;
            if(isdigit(chara))
                if(!firstFound)
                {
                    first = chara - '0';
                    firstFound = true;
                }
                else
                {
                    last  = chara - '0';
                    lastFound = true;
                }
        }
        if(!lastFound)
            last = first;

        result += (first * 10) + last;
        first = 0;
        last  = 0;
        firstFound = false;
        lastFound  = false;
    }
    cout << "RESULT -> " << result << endl;
}

int match(string word)
{
    if (word.find("zero") != string::npos)
        return 0;
    if (word.find("one") != string::npos)
        return 1;
    if (word.find("two") != string::npos)
        return 2;
    if (word.find("three") != string::npos)
        return 3;
    if (word.find("four") != string::npos)
        return 4;
    if (word.find("five") != string::npos)
        return 5;
    if (word.find("six") != string::npos)
        return 6;
    if (word.find("seven") != string::npos)
        return 7;
    if (word.find("eight") != string::npos)
        return 8;
    if (word.find("nine") != string::npos)
        return 9;
    return -1;
}

void e2(vector<string> input)
{
    int result = 0;
    int first  = 0;
    int last   = 0;
    bool firstFound = false;
    bool lastFound  = false;

    string window;

    for(string line : input)
    {
        /* cout << line << endl; */
        for(char chara : line)
        {
            /* cout << chara << endl; */
            if(isdigit(chara))
            {
                if(!firstFound)
                {
                    first = chara - '0';
                    firstFound = true;
                }
                else
                {
                    last  = chara - '0';
                    lastFound = true;
                }
                window = "";
            }
            else
                window += chara;

            // match
            if(!firstFound)
            {
                int aux = match(window);
                if (aux != -1)
                {
                    first = aux;
                    firstFound = true;
                    /* cout << "found FIRST -> " << window << " " << first << endl; */
                }
            }
            else
            {
                int aux = match(window);
                if (aux != -1)
                {
                    last = aux;
                    lastFound = true;
                }
            }
            /* cout << "WINDOW:" << window << endl; */
            // shift window
            if (window.length() >= 5)
            {
                window = window.erase(0,1);
            }
        }
        window = "";     // clean window
        if(!lastFound)
            last = first;

        /* cout << first << "," << last << endl; */

        result += (first * 10) + last;
        first = 0;
        last  = 0;
        firstFound = false;
        lastFound  = false;
    }
    cout << "RESULT -> " << result << endl;
}

int main() {
    // INPUT
    /* ifstream input_file("../../input/01mini2"); */
    ifstream input_file("../../input/01");
    if (!input_file.is_open()) {
        cerr << "Failed to open input file!" << endl;
        return 1;
    }
    vector<string> input;
    string line;
    while (getline(input_file, line)) {
        input.push_back(line);
    }
    /* input.push_back("");    // append empty line */

    // SOLVE
    /* e1(input); */
    e2(input);

    return 0;
}
