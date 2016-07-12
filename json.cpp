#include "json.hpp"
#include <iostream>
#include <fstream>
#include <string>

using json = nlohmann::json;
using namespace std;

int main(int argc, char **argv)
{
    // read in command line args
    if (argc < 2) {
        cout << "Usage: ./json <file.json>" << endl;
        return 1;
    }

    string filename(argv[1]);

    // open our file
    cout << "Opening file '" << filename << "'... ";
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "FAILED!" << endl;
        return 1;
    }

    cout << "SUCCESS!" << endl;

    // convert to json
    cout << endl << "Coverting to JSON... ";
    json j;
    file >> j;
    cout << "SUCCESS!" << endl;

    // close the file
    file.close();

    // now we can go through the file
    for (auto& e: j["4"]) {
        // show the filename
        cout << "File: " << e["filename"] << endl;

        // show species 2 info
        cout << "Number of species 2: " << e["2"].size() << endl;
        if (e["2"].size()) {
            cout << "{" << endl;
            for (auto& e2: e["2"]) {
                cout << "\t" << "(" << e2["center_x"] << ", " << e2["center_y"] << ")" << endl;
            }
            cout << "}" << endl;
        }

        // show species 1000000 info
        cout << "Number of species 1000000: " << e["1000000"].size() << endl;
        if (e["1000000"].size()) {
            cout << "{" << endl;
            for (auto& e2: e["1000000"]) {
                cout << "\t" << "(" << e2["center_x"] << ", " << e2["center_y"] << ")" << endl;
            }
            cout << "}" << endl;
        }

        // break between entries
        cout << endl << "-------------------------" << endl << endl;
    }

    return 0;
}
