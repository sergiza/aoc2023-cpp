#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "utils.cpp"
using namespace std;

#define CUBES_R 12
#define CUBES_G 13
#define CUBES_B 14

bool rgb(string line)
{
    int buffer = 0;
    int r = 0;
    int g = 0;
    int b = 0;
    bool checking = false;
    bool second_digit = false;

    for (char chara : line)
    {
        if (checking)
        {
            if (chara == 'r')
            {
                /* r += buffer; */
                if (buffer > r)
                    r = buffer;
                checking = false;
            }
            if (chara == 'g')
            {
                /* g += buffer; */
                if (buffer > g)
                    g = buffer;
                checking = false;
            }
            if (chara == 'b')
            {
                /* b += buffer; */
                if (buffer > b)
                    b = buffer;
                checking = false;
            }
        }
        else    // if (!checking)
            if (second_digit)
            {
                if (isdigit(chara))
                    buffer = (buffer * 10) + (chara - '0');
                checking = true;
                second_digit = false;
            }
            else
                if (isdigit(chara))
                {
                    buffer = chara - '0';
                    second_digit = true;
                }
    }
    cout << "R:" << r << "|G:" << g << "|B:" << b << "\t";
    if (r > CUBES_R)
        return false;
    if (g > CUBES_G)
        return false;
    if (b > CUBES_B)
        return false;
    return true;
}

// Determine which games would have been possible if the bag had been loaded with only 
// 12 red cubes     13 green cubes      14 blue cubes
// What is the sum of the IDs of those games?
void e1(vector<string> input)
{
    int sum = 0;
    for (string line : input)
    {
        // Game Nº
        line = line.erase(0, 5);
        int n_game = line[0] - '0';
        //digits...
        line = line.erase(0, 1);
        while (isdigit(line[0]))
        {
            n_game = (n_game * 10) + (line[0] - '0');
            line = line.erase(0, 1);
        }
        //
        line = line.erase(0, 2);

        // RGB
        cout << n_game << "->\t" << line << "\t";
        bool game = rgb(line);
        if (game)
        {
            cout << "Possible" << endl;
            sum += n_game;
            /* cout << "RESULT -> " << sum << endl; */
        }
        else
            cout << "Impossible" << endl;
    }
    cout << "RESULT -> " << sum << endl;
}

void e2(vector<string> input)
{
}

int main() {
    // INPUT
    /* ifstream input_file("../../input/02mini"); */
    ifstream input_file("../../input/02");
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
    e1(input);
    /* e2(input); */

    return 0;
}
