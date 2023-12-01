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
        cout << "RESULT (temp) -> " << result << "first:" << first << "last:" << last << endl;
        first = 0;
        last  = 0;
        firstFound = false;
        lastFound  = false;
    }
    cout << "RESULT -> " << result << endl;
}

void e2(vector<string> input)
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
        cout << "RESULT (temp) -> " << result << "first:" << first << "last:" << last << endl;
        first = 0;
        last  = 0;
        firstFound = false;
        lastFound  = false;
    }
    cout << "RESULT -> " << result << endl;
}

int main() {
    // INPUT
    ifstream input_file("../../input/01mini");
    /* ifstream input_file("../../input/01"); */
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
