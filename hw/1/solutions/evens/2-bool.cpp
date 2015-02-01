/*
 * =====================================================================================
 *
 *       Filename:  2.cpp
 *
 *    Description:  Solution to the second problem of the `evens' section
 *                  (uses bool matrix).
 *
 *        Version:  1.0
 *        Created:  28.01.2015  5,36,07
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

const int MAX_SIZE = 1000;

void write_primes(size_t n)
{
    bool a[MAX_SIZE] = {};
    size_t i = 2;

    while (i * i <= n)
    {
        for (size_t j = i * i; j <= n; j += i)
            a[j - 2] = true;

        i++;

        while (a[i - 2])
            i++;
    }

    for (size_t i = 2; i <= n; i++)
        if (!a[i - 2])
            cout << i << " ";

    cout << endl;
}

int main()
{
    size_t n;
    cin >> n;

    write_primes(n);

    return 0;
}

