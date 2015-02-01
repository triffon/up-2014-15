/*
 * =====================================================================================
 *
 *       Filename:  3.cpp
 *
 *    Description:  Solution to the third problem of the `odds' section.
 *
 *        Version:  1.0
 *        Created:   1.02.2015  4,32,33
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

const size_t MAX_SIZE = 1000;
const char CASE_CHARSET_DIFF = 'a' - 'A', WORD_DELIMITER = ' ';

bool isUpperLetter(char c)
{
    return c >= 'A' && c <= 'Z';
}

bool isLowerLetter(char c)
{
    return c >= 'a' && c <= 'z';
}

bool isInnerWordChar(char c)
{
    return isUpperLetter(c) || isLowerLetter(c) || c == '-';
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

const char* goToEndOfWord(const char* s)
{
    while (isLeftMatchedChar(*s))
        s++;

    while (isInnerWordChar(*s))
        s++;

    while (isRightMatchedChar(*s))
        s++;

    return s;
}

// Ако изречението е невалидно, връщаме NULL
char* reverseWords(char* rev, const char* s)
{    
    if (!s)
        return NULL;

    char* revcur = rev;

    while (*s && !isStopChar(*s))
    {
        const char* end = goToEndOfWord(s);

        if (s == end || *end != WORD_DELIMITER && !isDelimiterChar(*end))
            return NULL;

        if (s == --end)
            *revcur++ = *end++;
        else
        {
            *revcur++ = isUpperLetter(*s) ? toUpper(*end) : *end;

            const char* mid = end++ - 1;

            while (mid >= s)
                *revcur++ = *mid--;

            *(revcur - 1) = toLower(*(revcur - 1));
        }

        *revcur++ = *end;

        if (!isStopChar(*end) && isDelimiterChar(*end++))
        {
            if (*end != WORD_DELIMITER)
                return NULL;

            *revcur++ = *end++;
        }

        s = end;
    }

    if (!isStopChar(*s))
        return NULL;

    *revcur = 0;
    return rev;
}

int main()
{
    char s[MAX_SIZE], rev[MAX_SIZE];
    cin.getline(s, MAX_SIZE);

    cout << reverseWords(rev, s) << endl;

    return 0;
}

