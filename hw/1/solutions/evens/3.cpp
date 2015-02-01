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
#include <cstring>

using namespace std;

const int MAX_SIZE = 1000;
const char CASE_CHARSET_DIFF = 'a' - 'A', WORD_DELIMITER = ' ';

bool isInnerWordChar(char c)
{
    return c == '-' || c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z';
}

bool isQuote(char c)
{
    return c == '"' || c == '\'';
}

bool isLeftMatchedChar(char c)
{
    return isQuote(c) || c == '(';
}

bool isRightMatchedChar(char c)
{
    return isQuote(c) || c == ')';
}

bool isStopChar(char c)
{
    return c == '!' || c == '.' || c == '?';
}

bool isDelimiterChar(char c)
{
    return c == ',' || c == ':' || c == ';';
}

char toUpper(char c)
{
    return c >= 'a' && c <= 'z' ? c - CASE_CHARSET_DIFF : c;
}

char toLower(char c)
{
    return c >= 'A' && c <= 'Z' ? c + CASE_CHARSET_DIFF : c;
}

void swap(char* a, char* b)
{
    char x = *a;
    *a = *b;
    *b = x;
}

const char* goToEnd(const char* s)
{ 
    while (*s)
        s++;

    return s;
}

const char* appendBegin(char* rev, const char* beg, const char* mid)
{
    while (mid >= beg)
    {
        if (*mid == '(')
            strcat(rev, ")");
        else
            strncat(rev, mid, 1);

        mid--;
    }

    return mid;
}

const char* appendEnd(char* rev, const char* s, const char* end)
{
    while (end >= s && isRightMatchedChar(*end))
    {
        if (*end == ')')
            strcat(rev, "(");
        else
            strncat(rev, end, 1);

        end--;
    }

    return end;
}

// Ако изречението е невалидно, връщаме NULL
char* reverseSentence(char* rev, const char* s)
{
    if (!s)
        return NULL;

    const char* end = goToEnd(s) - 1;

    if (end < s || !isStopChar(*end))
        return NULL;

    const char* stop = end--;

    if (end < s)
        return NULL;

    do
    {
        const char* mid = end = appendEnd(rev, s, end);

        if (mid < s)
            return NULL;

        while (mid >= s && isInnerWordChar(*mid))
            mid--;

        if (mid == end)
            return NULL;

        const char* beg = mid++;
        
        while (beg >= s && isLeftMatchedChar(*beg))
            beg--;

/*
        if (isInnerWordChar(*mid) && !isInnerWordChar(*end))
            if (*end != ')')
                strncat(rev, end, 1);
            else
                strcat(rev, "(");
*/

        if (++beg == s)
        {
            char first[2];
            first[0] = *mid;
            first[1] = 0;
            first[0] = toLower(first[0]);
            strcat(rev, first);

            strncat(rev, mid + 1, end - mid);
            appendBegin(rev, beg, mid - 1);
        }
        else
        {
            strncat(rev, mid, end - mid + 1);
            appendBegin(rev, beg--, mid - 1);

            if (*beg != WORD_DELIMITER)
                return NULL;

            if (--beg < s)
                return NULL;

            if (isDelimiterChar(*beg))
                strncat(rev, beg, 1);

            strncat(rev, beg + 1, 1);
        }

        end = beg - 1;
    }
    while (end >= s);

    strncat(rev, stop, 1);

    char* first = rev;

    while (*first && isLeftMatchedChar(*first))
        first++;

    if (isInnerWordChar(*first))
        *first = toUpper(*first);

/*
    char *p = rev, *lp = NULL;
    int b = 0;

    while (*p)
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
*/

    return rev;
}

int main()
{
    char s[MAX_SIZE], rev[MAX_SIZE];
    cin.getline(s, MAX_SIZE);

    cout << reverseSentence(rev, s) << endl;

    return 0;
}
