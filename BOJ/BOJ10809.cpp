#include <iostream>

#define ALPHA_MAX   26

int alpha[ALPHA_MAX];

using namespace std;

int main()
{
    // init.
    for(int i = 0; i < ALPHA_MAX; ++i)
    {
        alpha[i] = -1;
    }
    string alphaSet = "";
    int argIdx = -1;

    // get input
    cin >> alphaSet;

    // process
    for(auto& arg : alphaSet)
    {
        ++argIdx;
        if(alpha[(int)arg-(int)'a'] != -1) continue;
        alpha[(int)arg-(int)'a'] = argIdx;
    }

    // print output
    for(auto& arg: alpha)
    {
        cout << arg << " ";
    }
}
