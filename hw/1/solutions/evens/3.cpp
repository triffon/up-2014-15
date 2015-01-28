/*
 * =====================================================================================
 *
 *       Filename:  3.cpp
 *
 *    Description:  Solution to the third problem of the `evens' section.
 *
 *        Version:  1.0
 *        Created:  28.01.2015  6,00,07
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
const char diff = 'a' - 'A';

bool isWordChar(char c)
{
    return c == '(' || c == ')' || c == '-' || c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z';
}

char* skipWhitespaceReverse(const char* s)
{
    while (*s == ' ')
        s--;

    return s;
}

char* goToEnd(const char* s)
{    
    while (*s)
        s++;

    return s;
}

char toUpper(char c)
{
    return c >= 'a' && c <= 'z' ? c - diff : c;
}

char toLower(char c)
{
    return c >= 'A' && c <= 'Z' ? c + diff : c;
}

void swap(char* a, char* b)
{
    char x = *a;
    *a = *b;
    *b = x;
}

// Ако изречението е невалидно, връщаме NULL
char* reverseSentence(const char* s)
{
    if (!s)
        return NULL;

    char* end = goToEnd(s);
    end--;

    if (end < s || *end != '!' && *end != '.' && *end != '?')
        return NULL;

    end--;

    char rev[MAX_SIZE];
    char* beg = end;
    bool is_first = true;

    while (beg >= s)
    {
        while (beg >= s && isWordChar(*beg))
            beg--;

        if (beg == end)
            return NULL;

        beg++;

        if (beg < s)
        {
            char first[2];
            strncat(first, beg, 1);
            *first = toLower(*first);
            strcat(rev, first);
            strncat(rev, beg + 1, end - beg);
        }
        else
        {
            strncat(rev, beg, end - beg + 1);
            end = beg - 1;

            if (*end != ' ')
                return NULL;

            end--;

            if (end < s)
                return NULL;

            if (*end == ',' || *end == ':' || *end == ';')
                strncat(rev, end, 1);

            strncat(rev, end + 1, 1);
        }
    }

    *rev = toUpper(*rev);
    char *p = rev, *lp = NULL;
    int b = 0;

    while (p)
    {
        if (*p == '(')
        {
            b++;

            if (lp && b == 0)
            {
                swap(p, lp);
                lp = NULL;
            }
        }
        else if (*p == ')')
        {
            b--;

            if (b == -1)
                lp = p;
        }

        p++;
    }

    cout << rev << endl;
    return 0;
}
