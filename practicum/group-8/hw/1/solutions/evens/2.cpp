/*
 * =====================================================================================
 *
 *       Filename:  2.cpp
 *
 *    Description:  Solution to the second problem of the `evens' section.
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

const size_t MAX_SIZE = 1000;

void write_primes(size_t n)
{
    if (n < 2)
        return;

    size_t a[MAX_SIZE];

    for (size_t i = 2; i <= n; i++)
        a[i - 2] = i;

    size_t i = 2;

    while (i * i <= n)
    {
        for (size_t j = i * i; j <= n; j += i)
            a[j - 2] = 1;

        i++;

        while (a[i - 2] == 1)
            i++;
    }

    for (size_t i = 0; i <= n - 2; i++)
        if (a[i] > 1)
            cout << a[i] << " ";

    cout << endl;
}

int main()
{
    size_t n;
    cin >> n;

    write_primes(n);

    return 0;
}

