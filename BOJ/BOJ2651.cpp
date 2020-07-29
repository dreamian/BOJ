#include <stdio.h>

#define MAX_STATION 105

int maxDist;

struct Station
{
    int _time;
    int _accumTime;
    int _interDist;
    int _prevStation;
    int _dpInterDist;

    Station(): _prevStation(-1) {}
    void getInterDist()
    {
        scanf("%d", &_interDist);
    }
    void getTime()
    {
        scanf("%d", &_time);
    }
};

Station station[MAX_STATION + 2];

void printArg(int idx, int cnt)
{
    if(idx == 0)
    {
        printf("%d\n", cnt - 1);
        return;
    }

    ++cnt;
    printArg(station[idx]._prevStation, cnt);
    if(station[idx]._prevStation != 0)
    {
        printf("%d ", station[idx]._prevStation);
    }
}

int main()
{
    int stNum;
    scanf("%d", &maxDist);
    scanf("%d", &stNum);

    /* Get Distance */
    for(int i=1;i<=stNum+1;++i)
    {
        station[i].getInterDist();
    }

    /* Get Time Info. */
    for(int i=1;i<stNum+1;++i)
    {
        station[i].getTime();
    }

    for(int i=1;i<=stNum+1;++i)
    {
        station[i]._dpInterDist = station[i-1]._dpInterDist + station[i]._interDist;
    }

    /* Dynamic Programming */
    for(int i=1;i<=stNum+1;++i)
    {
        int tarIdx = i - 1;

        for(int j=0;j<=i-1;++j)
        {
            if
            (
                station[j]._accumTime < station[tarIdx]._accumTime
                && station[i]._dpInterDist - station[j]._dpInterDist <= maxDist
            )
            {
                tarIdx = j;
            }
        }

        station[i]._prevStation = tarIdx;
        station[i]._accumTime = station[tarIdx]._accumTime + station[i]._time;
    }

    printf("%d\n", station[stNum+1]._accumTime);
    if(station[stNum+1]._accumTime != 0)
    {
        printArg(stNum + 1, 0);
        printf("\n");
    }
    else
    {
        printf("0\n");
    }

    return 0;
}
