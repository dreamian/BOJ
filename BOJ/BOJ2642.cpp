/**
 * 1. all six surfaces must be connected.
 * 2. each surface must have a block two spaces apart from that.
 */
#include <stdio.h>

#define MAX_LEN		6

int board[MAX_LEN][MAX_LEN];

void _swap(int& a, int& b)
{
    a ^= b;
    b ^= a;
    a ^= b;
}

struct BLOCK {
    int row;
    int col;
    int counter;

    void get(int _row, int _col)
    {
    row = _row;
    col = _col;
    counter = -1;
    }
} target[MAX_LEN];

int blkCount = 0;
int ansIdx = -1;

bool in_range(int row, int col)
{
    if (row < 0 || row >= MAX_LEN || col < 0 || col >= MAX_LEN)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool isCoupled(int a, int b)
{
    int aRow = target[a].row;
    int aCol = target[a].col;

    int bRow = target[b].row;
    int bCol = target[b].col;

    if (aRow > bRow) _swap(aRow, bRow);
    if (aCol > bCol) _swap(aCol, bCol);

    int row = -1;
    int col = -1;

    if (aRow + 2 == bRow)
    {
        for (col = aCol; col <= bCol; ++col)
        {
            if (board[aRow + 1][col] == 0)
            {
                break;
            }
        }

        if (col == bCol + 1)
        {
            return true;
        }
    }

    if (aCol + 2 == bCol)
    {
        for (row = aRow; row<= bRow; ++row)
        {
            if (board[row][aCol + 1] == 0)
            {
                break;
            }
        }

        if (row == bRow + 1)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    //freopen("sample_test.txt", "r", stdin);
    for (int row = 0; row < MAX_LEN; ++row)
    {
        for (int col = 0; col < MAX_LEN; ++col)
        {
            scanf("%d", &board[row][col]);
            if (board[row][col] != 0)
            {
                if (board[row][col] == 1)
                {
                    ansIdx = blkCount;
                }
                target[blkCount++].get(row, col);
            }
        }
    }

    if (blkCount != MAX_LEN)
    {
        printf("0\n");
        return 0;
    }

    for (int i = 0; i < MAX_LEN; ++i)
    {
        if (target[i].counter != -1) { continue; }

        for (int j = i + 1; j < MAX_LEN; ++j)
        {
            if (target[j].counter != -1) { continue; }

            if (isCoupled(i, j))
            {
                target[i].counter = board[target[j].row][target[j].col];
                target[j].counter = board[target[i].row][target[i].col];
            }
        }

        if (target[i].counter == -1)
        {
            printf("0\n");
            return 0;
        }
    }

    printf("%d\n", target[ansIdx].counter );
}
