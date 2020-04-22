#include <unistd.h>
#include <array>
#include <vector>
#include <iostream>

using namespace std;

static array<char, 64> l_data = {'c'};
static char l_choices = 's';

void useAfterFree()
{
    auto chars = new char[32];
    delete [] chars;

    chars[2] = 'b';
}

void globalOverflow()
{
    for (int idx=0; idx<=l_data.size(); idx++)
    {
        l_data[idx] = 0xF;
    }

    cout << "l_choices: " << l_choices << endl;
}

void heapOverflow()
{
    auto flags = new array<bool, 32>;

    for (int idx=0; idx<=flags->size(); idx++)
    {
        (*flags)[idx] = true;
    }

    delete flags;
}

void memLeak()
{
    auto flags = new array<bool, 32>;

    for (int idx=0; idx<flags->size(); idx++)
    {
        (*flags)[idx] = true;
    }
    // memory leak: flags
}

void stackOverflow()
{
    array<int, 16> arr = {};

    for (int idx=0; idx<=arr.size(); idx++)
    {
        arr[idx] = 0xF;
    }
}

void uninitMemRead()
{
    int arr[10];

    cout << arr[5] << endl;
}

void violation()
{
    vector<vector<int>> grid;

    grid.reserve(128); // resize
    grid[2].push_back(1);
}

int printHelp(char *prog)
{
    cout << "Usage: " << prog << " [option]" <<endl;
    cout << "Options:" << endl;
    cout << "   -f use after free" << endl;
    cout << "   -g global buffer overflow" << endl;
    cout << "   -h heap buffer overflow" << endl;
    cout << "   -l memory leak" << endl;
    cout << "   -s stack buffer overflow" << endl;
    cout << "   -u uninitialized memory read" << endl;
    cout << "   -v violation(segv)" << endl;

    return -1;
}

int main(int argc, char **argv)
{
    // gcc 4.8 above , libasan installed
    char ch = ' ';

    if (2 != argc) return printHelp(argv[0]);

    while ((ch = getopt(argc, argv, "fghlsuv")) != -1)
    {
        switch (ch)
        {
            case 'f':
                useAfterFree();
                break;
            case 'g':
                globalOverflow();
                break;
            case 'h':
                heapOverflow();
                break;
            case 'l':
                memLeak();
                break;
            case 's':
                stackOverflow();
                break;
            case 'u':
                uninitMemRead();
                break;
            case 'v':
                violation();
                break;
            default:
                return printHelp(argv[0]);
                break;
        }
    }

    return 0;
}
