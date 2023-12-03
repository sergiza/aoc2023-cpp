#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "utils.cpp"
using namespace std;

bool rgb(string line)
{
    int buffer = 0;
    int r = 0;
    int g = 0;
    int b = 0;
    bool checking = false;
    for (char chara : line)
    {
        if (checking)
        {
            if (chara == 'r')
            {
                r += buffer;
                checking = false;
            }
            if (chara == 'g')
            {
                g += buffer;
                checking = false;
            }
            if (chara == 'b')
            {
                b += buffer;
                checking = false;
            }
        }
        else    // if (!checking)
            if (isdigit(chara))
            {
                buffer = chara - '0';
                checking = true;
                // FIX: pueden ser 2 digitos
            }
    }
    cout << "R " << r << " , G " << g << " , B " << b << endl;
    if (r > 12)
        return false;
    if (g > 13)
        return false;
    if (b > 14)
        return false;
    return true;
}

// Determine which games would have been possible if the bag had been loaded with only 
// 12 red cubes     13 green cubes      14 blue cubes
// What is the sum of the IDs of those games?
void e1(vector<string> input)
{
    for (string line : input)
    {
        // Game Nº
        line = line.erase(0, 5);
        int n_game = line[0] - '0';
        line = line.erase(0, 3);

        // RGB
        cout << n_game << "->" << line << endl;
        bool game = rgb(line);
        if (game)
            cout << "Possible" << endl;
        else
            cout << "Impossible" << endl;
    }
}

void e2(vector<string> input)
{
}

int main() {
    // INPUT
    ifstream input_file("../../input/02mini");
    /* ifstream input_file("../../input/02"); */
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
