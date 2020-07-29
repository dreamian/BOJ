#include <iostream>
#include <algorithm>

#define MAX_STR_PATTERN     100

using namespace std;

int n, m;
int patternCount, ansCount;
string patternList[MAX_STR_PATTERN];
string ansList[MAX_STR_PATTERN];

void regPattern(string str)
{
    patternList[patternCount++] = str;
    for(int i = 1; i < n; ++i)
    {
        patternList[patternCount].append(patternList[patternCount - 1], 1, patternList[patternCount - 1].npos);
        patternList[patternCount] += patternList[patternCount - 1][0];
        ++patternCount;
    }
}

bool checkPattern(string str)
{
    for(int idx = 0; idx < patternCount; ++idx)
    {
        if(str == patternList[idx])
        {
            return true;
        }
    }

    return false;
}

int main(void)
{
    // freopen("sample_input.txt","r", stdin);

    patternCount = ansCount = 0;

    cin >> n;
    string targetStr = "";
    for(int i=0;i<n;++i)
    {
        char target;
        cin >> target;
        targetStr += target;
    }

    // reverse dir
    string revTargetStr(targetStr);

    /**
     * RIGHT(1) -> LEFT(3)
     * UP(2)    -> DOWN(4)
     * LEFT(3)  -> RIGHT(1)
     * DOWN(4)  -> UP(2)
     */

    for(int idx = 0; idx < n ; ++idx)
    {
        int arg2Num = (int)(revTargetStr[idx] - '0');
        arg2Num = (arg2Num + 2) % 4;
        if(arg2Num == 0) arg2Num += 4;
        revTargetStr[idx] = (char)(arg2Num + '0');
    }

    reverse(revTargetStr.begin(), revTargetStr.end());

    // make pattern
    regPattern(targetStr);
    regPattern(revTargetStr);

    cin >> m;
    for(int idx = 0; idx < m; ++idx)
    {
        string schTarget = "";
        for(int i=0;i<n;++i)
        {
            char target;
            cin >> target;
            schTarget += target;
        }

        if(checkPattern(schTarget))
        {
            ansList[ansCount++] = schTarget;
        }
    }

    // print
    cout << ansCount << endl;
    for(int idx = 0; idx < ansCount; ++idx)
    {
        for(auto& arg: ansList[idx])
        {
            cout << arg << " ";
        }
        cout << endl;
    }
}
