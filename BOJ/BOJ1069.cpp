/**
 * Ad-Hoc Algorithm
 */
#include <stdio.h>
#include <cmath>

int X, Y, D, T;
double ans = 0.0;
double L = 0.0;

static double _min(double _a, double _b, double _c)
{
    double ret = _a;

    ret = ret - _b < 0E-9 ? ret : _b;
    ret = ret - _c < 0E-9 ? ret : _c;

    return ret;
}

int main(void)
{
    while(scanf("%d %d %d %d", &X, &Y, &D, &T) != EOF)
    {
        ans = 1e+9;
        L = sqrt(X*X + Y*Y);

        int numOfJump = (int) floor(L/D);

        if(L - D >= 1E-9)
        {
            // just walk
            double justWalk = L;
            // minimumJump, and walk
            double minJumpAndWalk = (numOfJump * T) + (L - (numOfJump * D));
            // minimumJump + 1
            double minJumpAndBackWalk = ((numOfJump + 1) * T);
            ans = _min(justWalk, minJumpAndWalk, minJumpAndBackWalk);
        }
        else
        {
            // just walk
            double justWalk = L;
            // jump twice
            double doubleJump = (2 * T);
            // minimumJump + 1, and back walk
            double minJumpAndBackWalk = (T) + (D - L);
            // double minJumpAndBackWalk = ((numOfJump + 1) * T) + (((numOfJump + 1) * D) - L);
            ans = _min(justWalk, doubleJump, minJumpAndBackWalk);
        }
        printf("%.13f\n", ans);
    }
}
