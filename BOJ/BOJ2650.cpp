#include <stdio.h>

#define VERTEX_MAX  50
#define MAX_INT     (1e+9)

struct Vector
{
    long long _i;
    long long _j;
    void printArg(void)
    {
        printf("i: %lld,\t j: %lld\n", _i, _j);
    }
    bool operator>(const Vector& other)
    {
        if(_i > other._i)
        {
            return true;
        }
        else if (_i == other._i)
        {
            if(_j > other._j)
            {
                return true;
            }
        }
        return false;
    }
    bool operator<=(const Vector& other)
    {
        if(_i < other._i)
        {
            return true;
        }
        else if(_i == other._i)
        {
            if(_j <= other._j)
            {
                return true;
            }
            else return false;
        }

        return false;
    }
};

static bool CheckIncluded (Vector& a, Vector& b, Vector& c, Vector& d)
{
    // C--A--B--D
    // A--C--D--B
    if(c._i == a._i)
    {
        if( (c._j < a._j && b._j < d._j) ||
            (a._j < c._j && d._j < b._j)
        )
        {
            return true;
        }
        else return false;
    }
    else
    {
        if( (c._i < a._i && b._i < d._i) ||
            (a._i < c._i && d._i < b._i)
        )
        {
            return true;
        }
        else return false;
    }

    return true;
}

typedef struct
{
    long long x1;
    long long y1;
    long long x2;
    long long y2;
    int intercept;
} Line;

static Line line[VERTEX_MAX/2];
static int  itctSum;
static int  maxItct;

static void _swap (Vector &a, Vector&b)
{
    a._i ^= b._i;
    b._i ^= a._i;
    a._i ^= b._i;
    a._j ^= b._j;
    b._j ^= a._j;
    a._j ^= b._j;
}

static bool checkIntercept (int i, int j)
{
    long long temp;
    int ccwABC, ccwABD, ccwCDA, ccwCDB;

    Vector _ab = {(line[i].x2-line[i].x1), (line[i].y2-line[i].y1)};
    Vector _ac = {(line[j].x1-line[i].x1), (line[j].y1-line[i].y1)};
    Vector _ad = {(line[j].x2-line[i].x1), (line[j].y2-line[i].y1)};
    temp = _ab._i*_ac._j - _ab._j*_ac._i;
    if(temp == 0)
    {
        ccwABC = 0;
    }
    else if(temp > 0)
    {
        ccwABC = 1;
    }
    else
    {
        ccwABC = -1;
    }
    temp = _ab._i*_ad._j - _ab._j*_ad._i;
    if(temp == 0)
    {
        ccwABD = 0;
    }
    else if(temp > 0)
    {
        ccwABD = 1;
    }
    else
    {
        ccwABD = -1;
    }

    Vector _cd = {(line[j].x2-line[j].x1), (line[j].y2-line[j].y1)};
    Vector _ca = {(line[i].x1-line[j].x1), (line[i].y1-line[j].y1)};
    Vector _cb = {(line[i].x2-line[j].x1), (line[i].y2-line[j].y1)};
    temp = _cd._i*_ca._j - _cd._j*_ca._i;
    if(temp == 0)
    {
        ccwCDA = 0;
    }
    else if(temp > 0)
    {
        ccwCDA = 1;
    }
    else
    {
        ccwCDA = -1;
    }
    temp = _cd._i*_cb._j - _cd._j*_cb._i;
    if(temp == 0)
    {
        ccwCDB = 0;
    }
    else if(temp > 0)
    {
        ccwCDB = 1;
    }
    else
    {
        ccwCDB = -1;
    }

    int ccwAB = ccwABC*ccwABD;
    int ccwCD = ccwCDA*ccwCDB;

    //Check pre-condition
    if(ccwAB == 0 && ccwCD == 0)
    {
        Vector a = { line[i].x1, line[i].y1 };
        Vector b = { line[i].x2, line[i].y2 };
        Vector c = { line[j].x1, line[j].y1 };
        Vector d = { line[j].x2, line[j].y2 };
        // printf("==============================================\n");
        // a.printArg(); b.printArg(); c.printArg(); d.printArg();
        // printf("==============================================\n");
        if(a > b) _swap(a, b);
        if(c > d) _swap(c, d);

        if(CheckIncluded(a, b, c, d)) return false;

        bool retA = (c <= b && a <= d);
        // printf("==============================================\n");
        // a.printArg(); b.printArg(); c.printArg(); d.printArg();
        // printf("ret: %s\n", retA ? "true" : "false");
        // printf("==============================================\n");

        return retA;
    }

    // if( (ccwAB == 0 && ccwCD != 0) ||
    //     (ccwAB != 0 && ccwCD == 0)
    // )
    // {
    //     printf("Yes\n");
    // }

    return ccwAB <= 0 && ccwCD <= 0;
}

inline void setLine(int opt, int dist, int idx, int fs)
{
    switch(opt)
    {
        case 1:
            if(fs == 0)
            {
                line[idx].y1 = MAX_INT;
                line[idx].x1 = dist;
            }
            else
            {
                line[idx].y2 = MAX_INT;
                line[idx].x2 = dist;
            }
            break;
        case 2:
            if(fs == 0)
            {
                line[idx].y1 = 0;
                line[idx].x1 = dist;
            }
            else
            {
                line[idx].y2 = 0;
                line[idx].x2 = dist;
            }
            break;
        case 3:
            if(fs == 0)
            {
                line[idx].y1 = MAX_INT - dist;
                line[idx].x1 = 0;
            }
            else
            {
                line[idx].y2 = MAX_INT - dist;
                line[idx].x2 = 0;
            }
            break;
        case 4:
            if(fs == 0)
            {
                line[idx].y1 = MAX_INT - dist;
                line[idx].x1 = MAX_INT;
            }
            else
            {
                line[idx].y2 = MAX_INT - dist;
                line[idx].x2 = MAX_INT;
            }
            break;
        default:
            printf("Error!\n");
            break;
    }
}

int main()
{
    itctSum = 0;
    maxItct = 0;
    int n;
    scanf("%d", &n);

    // input
    for(int i=0;i<n/2;++i)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        setLine (a, b, i, 0);
        scanf("%d %d", &a, &b);
        setLine (a, b, i, 1);
        line[i].intercept = 0;
    }

    // process
    for(int i=0;i<n/2;++i)
    {
        for(int j=0;j<n/2;++j)
        {
            if(i == j) { continue; }
            if(checkIntercept(i, j))
            {
                ++line[i].intercept;
                ++itctSum;
                maxItct = maxItct > line[i].intercept ? maxItct : line[i].intercept;
            }
        }
    }

    // print
    printf("%d\n%d\n", itctSum/2, maxItct);
}
