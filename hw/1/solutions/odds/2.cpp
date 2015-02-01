/*
 * =====================================================================================
 *
 *       Filename:  2.cpp
 *
 *    Description:  Solution to the second problem of the `odds' section.
 *
 *        Version:  1.0
 *        Created:   1.02.2015  3,41,30
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
    if (n == 2)
        cout << 2 << endl;

    if (n <= 2)
        return;
    
    n = n / 2 - (n % 2 ? 0 : 1);

    size_t a[MAX_SIZE];

    for (size_t i = 1; i <= n; i++)
        a[i - 1] = i;

    size_t i = 1, k;

    do
    {
        size_t j = i;

        do
        {
            k = i + j + 2 * i * j;
            a[k - 1] = 0;
            j++;
        }
        while (k <= n);

        i++;
    }
    while (k <= n);

    cout << 2 << " ";

    for (size_t i = 0; i <= n - 1; i++)
        if (a[i] > 0)
            cout << 2 * a[i] + 1 << " ";

    cout << endl;
}

int main()
{
    size_t n;
    cin >> n;

    write_primes(n);

    return 0;
}

