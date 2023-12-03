#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "utils.cpp"
using namespace std;

void e1(vector<string> input)
{
    vector <int> part_number;
    vector < tuple<int,int> > pending;              // position,value
    vector < tuple<int,int> > pending_previous;
    char position = 0;
    /* part_number.push_back(1); */
    for (string line : input)
    {
        for (char chara : line)
        {

            position++;
        }
        // recorrer pending_previous comprobando posiciones *
        // una vez recorrido, pending_previous = pending
        pending_previous = pending;
    }
}

void e2(vector<string> input)
{
}

int main() {
    // INPUT
    ifstream input_file("../../input/03mini");
    /* ifstream input_file("../../input/03"); */
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
