/*
 * =====================================================================================
 *
 *       Filename:  2.cpp
 *
 *    Description:  Solution to the second problem of the `all' section.
 *
 *        Version:  1.0
 *        Created:  28.01.2015  5,05,48
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

int hamming_distance(const char* a, const char* b)
{
    int n = 0;

    while (a && b)
    {
        if (*a != *b)
            n++;

        a++;
        b++;
    }

    return n;
}

int main()
{
    char s1[MAX_SIZE], s2[MAX_SIZE];
    cin.getline(s1, MAX_SIZE);
    cin.getline(s2, MAX_SIZE);

    cout << hamming_distance(s1, s2);

    return 0;
}
