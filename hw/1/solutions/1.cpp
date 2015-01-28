/*
 * =====================================================================================
 *
 *       Filename:  1.cpp
 *
 *    Description:  Solution to the first problem of the `all' section.
 *
 *        Version:  1.0
 *        Created:  27.01.2015 19,21,01
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Radoslav Georgiev (sid), rgeorgiev583@gmail.com
 *        Company:  Faculty of Mathematics and Informatics at Sofia University
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

int fact(int n)
{
    int P = 1;

    for (int i = 2; i <= n; i++)
        P *= i;

    return P;
}

bool areEqual(int n, int m)
{
    double S = 0;

    for (int i = 1; i <= n; i++)
    {
        int P = 1;

        for (int j = i; j <= i + m; j++)
            P *= j;

        S += 1 / (double) P;
    }

    int P = 1;

    for (int i = n + 1; i <= n + m; i++)
        P *= i;

    return S == 1 / (double) m * (1 / (double) fact(m) - 1 / (double) P);
}

bool areEqualForAll(int a, int b)
{
    for (int i = 1; i <= a; i++)
        for (int j = 1; j <= b; j++)
            if (!areEqual(i, j))
                return false;

    return true;
}

int main()
{
    int n, m;

    cin >> n >> m;
    cout << (areEqualForAll(n, m) ? "Yes" : "No");

    return 0;
}
    
