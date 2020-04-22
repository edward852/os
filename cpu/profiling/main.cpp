#include <iostream>
#include <fstream>

using namespace std;

int printHelp(const char *prog)
{
    cout << "Usage: " << prog << " <file path>" << endl;
    return -1;
}

int main(int argc, char **argv) {
    if (2 != argc) return printHelp(argv[0]);

    ifstream ifs;

    ifs.open(argv[1], ifstream::in);
    if (!ifs.is_open())
    {
        cout << "Failed to open file: " << argv[1] << endl;
        return -1;
    }

    int words = 0;
    bool in_word = false;

    for (char ch=ifs.get(); ifs.good(); ch=ifs.get())
    {
        if (isspace(ch) && in_word)
        {
            words++;
            in_word = false;
        }

        in_word = isalpha(ch)? true: false;
    }
    cout << argv[1] << " " << words << " words" << endl;

    return 0;
}
