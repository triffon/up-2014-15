/*
 * =====================================================================================
 *
 *       Filename:  1.cpp
 *
 *    Description:  Solution to the first problem of the `evens' section.
 *
 *        Version:  1.0
 *        Created:  28.01.2015  5,20,28
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

size_t count(int a, int b)
{
    size_t n = 0;

    for (int i = a; i <= b; i++)
    {
        int t = i, d = t % 8;

        while (t && t % 8 == d)
            t /= 8;

        if (!t)
            n++;
    }

    return n;
}

int main()
{
    int a, b;
    cin >> a >> b;

    cout << count(a, b);

    return 0;
}

