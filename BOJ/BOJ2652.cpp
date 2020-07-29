/**
 * 1. Check the dimension of the given 'ㄷ' block by BFS. (M*N)
 * 2. Check the input is matched with the given block by referring the dimension for the given block of pre-calculated.
 * 3. Search the each side to find the depth of given block. (depth: u, v, w, x, y)
 */
#include <stdio.h>

#define MAX_BLKMAP_LEN  (50)
#define MAX_BLK_NUM     (25*25)

/**
 * TYPE DECL. & DEF.
 */

typedef enum {
    BLK_UP_DIR = 0,
    BLK_RIGHT_DIR,
    BLK_DOWN_DIR,
    BLK_LEFT_DIR,

    BLK_MAX_DIR
} enumBlkDir_type;

int     n;
int     blkMap[MAX_BLKMAP_LEN][MAX_BLKMAP_LEN];
bool    chkMap[MAX_BLKMAP_LEN][MAX_BLKMAP_LEN];
int     drow[BLK_MAX_DIR] = {-1, 0, 1, 0 };
int     dcol[BLK_MAX_DIR] = { 0, 1, 0, -1};

typedef struct {
    int u;
    int v;
    int w;
    int x;
    int y;
}   fuckBlk_type;
fuckBlk_type    fuck;

typedef struct {
    int row;
    int col;
} idx_type;

typedef struct {
    int m;
    int n;
} dimension_type;

typedef struct {
    idx_type        minIdx;
    idx_type        maxIdx;
    dimension_type  dim;
    enumBlkDir_type dir;
    void dbgPrint()
    {
        printf("#############################################################\n");
        printf("- minIdx\n");
        printf("-> row: %02d, col: %02d\n", minIdx.row, minIdx.col);
        printf("- maxIdx\n");
        printf("-> row: %02d, col: %02d\n", maxIdx.row, maxIdx.col);
        printf("- dim\n");
        printf("-> m: %02d, n: %02d\n", dim.m, dim.n);
        printf("- dir\n");
        printf("-> DIR: %d\n", dir);
        printf("#############################################################\n");
    }
    void init(int row, int col)
    {
        minIdx.row = maxIdx.row = row;
        minIdx.col = maxIdx.col = col;
        dim.m = dim.n = 0;
        dir = BLK_MAX_DIR;

        return;
    }
    int getDepth(int startRow, int startCol, int breakCond, enumBlkDir_type dir)
    {
        int depth = 0;

        while(1)
        {
            if(startRow < 0 || startRow >= n || startCol < 0 || startCol >= n) break;
            if(blkMap[startRow][startCol] == breakCond) break;
            startRow += drow[dir];
            startCol += dcol[dir];
            ++depth;
        }
        // printf("*************************************************\n");
        // printf("dep is %d\n", depth);
        // printf("sr: %d sc: %d, \n brcond: %d, dir: %d\n", startRow, startCol, breakCond, dir);
        // printf("*************************************************\n");
        return depth;
    }
    bool checkUpSide(int &x, int &y, int &w, const int height)
    {
        // printf("upside called\n");
        x = y = w = 0;

        w = getDepth(minIdx.row, maxIdx.col, 0, BLK_LEFT_DIR);
        if(w >= fuck.u)
        {
            return false;
        }

        x = getDepth(minIdx.row, maxIdx.col - w, 1, BLK_DOWN_DIR);
        if(x >= height)
        {
            return false;
        }

        y = getDepth(minIdx.row, maxIdx.col - w, 1, BLK_LEFT_DIR);
        if(y >= fuck.u)
        {
            return false;
        }

        // check validity
        for(int idx = minIdx.row; idx <= minIdx.row + x - 1 ; ++idx)
        {
            int tarDepth = getDepth(idx, maxIdx.col - w, 1, BLK_LEFT_DIR);
            if(tarDepth != y)
            {
                return false;
            }
        }

        return true;
    }
    bool checkDownSide(int &x, int &y, int &w, const int height)
    {
        // printf("downside called\n");
        x = y = w = 0;

        w = getDepth(maxIdx.row, minIdx.col, 0, BLK_RIGHT_DIR);
        if(w >= fuck.u)
        {
            return false;
        }

        x = getDepth(maxIdx.row, minIdx.col + w, 1, BLK_UP_DIR);
        if(x >= height)
        {
            return false;
        }

        y = getDepth(maxIdx.row, minIdx.col + w, 1, BLK_RIGHT_DIR);
        if(y >= fuck.u)
        {
            return false;
        }

        // check validity
        for(int idx = maxIdx.row; idx >= maxIdx.row - x + 1 ; --idx)
        {
            int tarDepth = getDepth(idx, minIdx.col + w, 1, BLK_RIGHT_DIR);
            if(tarDepth != y)
            {
                return false;
            }
        }

        return true;
    }
    bool checkLeftSide(int &x, int &y, int &w, const int height)
    {
        // printf("leftside called\n");
        x = y = w = 0;

        w = getDepth(minIdx.row, minIdx.col, 0, BLK_DOWN_DIR);
        if(w >= fuck.u)
        {
            return false;
        }

        x = getDepth(minIdx.row + w, minIdx.col, 1, BLK_RIGHT_DIR);
        if(x >= height)
        {
            return false;
        }

        y = getDepth(minIdx.row + w, minIdx.col, 1, BLK_DOWN_DIR);
        if(y >= fuck.u)
        {
            return false;
        }

        // check validity
        for(int idx = minIdx.col; idx <= minIdx.col + x - 1 ; ++idx)
        {
            int tarDepth = getDepth(minIdx.row + w, idx, 1, BLK_DOWN_DIR);
            if(tarDepth != y)
            {
                return false;
            }
        }

        return true;
    }
    bool checkRightSide(int &x, int &y, int &w, const int height)
    {
        // printf("rightside called\n");
        x = y = w = 0;

        w = getDepth(maxIdx.row, maxIdx.col, 0, BLK_UP_DIR);
        if(w >= fuck.u)
        {
            return false;
        }

        x = getDepth(maxIdx.row - w, maxIdx.col, 1, BLK_LEFT_DIR);
        if(x >= height)
        {
            return false;
        }

        y = getDepth(maxIdx.row - w, maxIdx.col, 1, BLK_UP_DIR);
        if(y >= fuck.u)
        {
            return false;
        }

        // check validity
        for(int idx = maxIdx.col; idx >= maxIdx.col - x + 1 ; --idx)
        {
            int tarDepth = getDepth(maxIdx.row - w, idx, 1, BLK_UP_DIR);
            if(tarDepth != y)
            {
                return false;
            }
        }

        return true;
    }
    int checkVCapacity(enumBlkDir_type dir)
    {
        int res = 1e+9;

        switch(dir)
        {
            case BLK_UP_DIR:
                for(int col = maxIdx.col; col >= minIdx.col; --col)
                {
                    int dep = getDepth(minIdx.row - 1, col, 1, dir);
                    res = res < dep ? res : dep;
                }
                break;
            case BLK_RIGHT_DIR:
                for(int row = maxIdx.row; row >= minIdx.row; --row)
                {
                    int dep = getDepth(row, maxIdx.col + 1, 1, dir);
                    res = res < dep ? res : dep;
                }
                break;
            case BLK_DOWN_DIR:
                for(int col = minIdx.col; col <= maxIdx.col; ++col)
                {
                    int dep = getDepth(maxIdx.row + 1, col, 1, dir);
                    res = res < dep ? res : dep;
                }
                break;
            case BLK_LEFT_DIR:
                for(int row = minIdx.row; row <= maxIdx.row; ++row)
                {
                    int dep = getDepth(row, minIdx.col - 1, 1, dir);
                    res = res < dep ? res : dep;
                }
                break;
            default:
                return -1;
        }

        return res;
    }
} blk_type;

const int QUEUE_ARR_SZ = MAX_BLK_NUM + 1;

typedef struct {
    idx_type    arr[QUEUE_ARR_SZ];
    int         sp;
    int         ep;

    void init()
    {
        sp = ep = 0;
    }
    void push(int row, int col)
    {
        arr[ep].row = row;
        arr[ep].col = col;
        ep = (ep + 1)%QUEUE_ARR_SZ;
    }
    idx_type pop(void)
    {
        ep = (ep + QUEUE_ARR_SZ - 1)%QUEUE_ARR_SZ;
        return {arr[ep].row, arr[ep].col};
    }
    bool isEmpty(void)
    {
        if(sp == ep)
        {
            return true;
        }
        else return false;
    }
} queue_type;

blk_type        blk[MAX_BLK_NUM];
int             ans[MAX_BLK_NUM];
int             blkCount;
int             ansCount;
queue_type      blkQueue;

/**
 * BFS (Search BLK)
 */
void _bfs(int i, int j, int blkIdx)
{
    chkMap[i][j] = true;
    blkQueue.push(i, j);

    while(! blkQueue.isEmpty())
    {
        idx_type schIdx = blkQueue.pop();
        for(int mov = BLK_UP_DIR; mov < BLK_MAX_DIR; ++mov)
        {
            int dr = schIdx.row + drow[mov];
            int dc = schIdx.col + dcol[mov];

            if(dr < 0 || dr >= n || dc < 0 || dc >= n) continue;
            if(chkMap[dr][dc] == true) continue;
            if(blkMap[dr][dc] != 1) continue;

            // check maxIdx
            blk[blkIdx].maxIdx.row = blk[blkIdx].maxIdx.row < dr ? dr : blk[blkIdx].maxIdx.row;
            blk[blkIdx].maxIdx.col = blk[blkIdx].maxIdx.col < dc ? dc : blk[blkIdx].maxIdx.col;

            chkMap[dr][dc] = true;
            blkQueue.push(dr, dc);
        }
    }

    // calc. dimension
    blk[blkIdx].dim.m = blk[blkIdx].maxIdx.row - blk[blkIdx].minIdx.row + 1;
    blk[blkIdx].dim.n = blk[blkIdx].maxIdx.col - blk[blkIdx].minIdx.col + 1;

    // check condition
    // #1. UP / DOWN candidate
    int xCand, yCand, wCand, vCapa;
    bool cond = false;
    if(fuck.u == blk[blkIdx].dim.n && fuck.x < blk[blkIdx].dim.m)
    {
        cond = blk[blkIdx].checkUpSide(xCand, yCand, wCand, blk[blkIdx].dim.m);
        if(cond)
        {
            vCapa = blk[blkIdx].checkVCapacity(BLK_UP_DIR);

            if(vCapa >= fuck.v && xCand == fuck.x && yCand == fuck.y && wCand == fuck.w)
            {
                ans[ansCount] = blkIdx;
                ++ansCount;
                return;
            }
        }
        cond = blk[blkIdx].checkDownSide(xCand, yCand, wCand, blk[blkIdx].dim.m);
        if(cond)
        {
            vCapa = blk[blkIdx].checkVCapacity(BLK_DOWN_DIR);
            if(vCapa >= fuck.v && xCand == fuck.x && yCand == fuck.y && wCand == fuck.w)
            {
                ans[ansCount] = blkIdx;
                ++ansCount;
                return;
            }
        }
    }
    // #2. LEFT/ RIGHT candidate
    if(fuck.u == blk[blkIdx].dim.m && fuck.x < blk[blkIdx].dim.n)
    {
        cond = blk[blkIdx].checkLeftSide(xCand, yCand, wCand, blk[blkIdx].dim.n);
        if(cond)
        {
            vCapa = blk[blkIdx].checkVCapacity(BLK_LEFT_DIR);
            if(vCapa >= fuck.v && xCand == fuck.x && yCand == fuck.y && wCand == fuck.w)
            {
                ans[ansCount] = blkIdx;
                ++ansCount;
                return;
            }
        }
        cond = blk[blkIdx].checkRightSide(xCand, yCand, wCand, blk[blkIdx].dim.n);
        if(cond)
        {
            vCapa = blk[blkIdx].checkVCapacity(BLK_RIGHT_DIR);
            if(vCapa >= fuck.v && xCand == fuck.x && yCand == fuck.y && wCand == fuck.w)
            {
                ans[ansCount] = blkIdx;
                ++ansCount;
                return;
            }
        }
    }
}

int main(void)
{
    // freopen("sample_input.txt","r",stdin);
    // freopen("sample_output.txt","w",stdout);

    // initialization
    blkCount = ansCount = 0;
    blkQueue.init();

    // get input
    scanf("%d", &n);
    scanf("%d%d%d%d%d", &fuck.u, &fuck.v, &fuck.w, &fuck.x, &fuck.y);
    for(int i=0;i<n;++i) for(int j=0;j<n;++j)
    {
        scanf("%d", &blkMap[i][j]);
    }

    // process
    for(int i=0;i<n;++i) for(int j=0;j<n;++j)
    {
        if(chkMap[i][j] == true || blkMap[i][j] == 0) continue;

        blk[blkCount].init(i, j);
        _bfs(i, j, blkCount);
        ++blkCount;
    }

    // // debug
    // for(int i=0;i<blkCount;++i)
    // {
    //     blk[i].dbgPrint();
    // }

    // print ans
    printf("%d\n", ansCount);
    for(int i=0; i < ansCount; ++i)
    {
        printf("%d %d\n", blk[ans[i]].minIdx.row + 1, blk[ans[i]].minIdx.col + 1);
    }

    return 0;
}
