#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * Algorithm Challenge – Level 3 | #43 Replace Words in a String (Custom Implementation)
 *
 * This program replaces words in a string using custom-built string processing functions instead of relying on built-in replace().
 *
 * The solution demonstrates how complex text operations can be decomposed into smaller reusable components.
 *
 * Core concepts:
 * - String tokenization (Split)
 * - Vector-based data processing
 * - Case-sensitive and case-insensitive comparison
 * - Custom text reconstruction (Join)
 */

// Splits a string into tokens based on a given delimiter
vector<string> SplitString(string S1, string Delim)
{
    vector<string> vString;
    short Pos = 0;
    string Token;

    while ((Pos = S1.find(Delim)) != string::npos)
    {
        Token = S1.substr(0, Pos);

        if (Token != "")
        {
            vString.push_back(Token);
        }

        // Remove processed part from the string
        S1.erase(0, Pos + Delim.length());
    }

    // Add the last remaining token
    if (S1 != "")
    {
        vString.push_back(S1);
    }

    return vString;
}

// Joins vector elements into a single string using a delimiter
string JoinString(vector<string> VecString, string Delim)
{
    string S1 = "";

    for (string &s : VecString)
    {
        S1 += s + Delim;
    }

    // Remove trailing delimiter
    return S1.substr(0, S1.length() - Delim.length());
}

// Converts all letters in a string to lowercase
string ToLowerAllLetterString(string S1)
{
    for (int i = 0; i < S1.length(); i++)
    {
        S1[i] = tolower(S1[i]);
    }

    return S1;
}

// Replaces a word using custom split & join logic
string ReplaceWordInStringUsingSplit(
    string S1,
    string StringToReplace,
    string ReplaceTo,
    bool MatchCase = true)
{
    vector<string> VString = SplitString(S1, " ");

    for (string &s : VString)
    {
        if (MatchCase)
        {
            if (s == StringToReplace)
            {
                s = ReplaceTo;
            }
        }
        else
        {
            if (ToLowerAllLetterString(s) ==
                ToLowerAllLetterString(StringToReplace))
            {
                s = ReplaceTo;
            }
        }
    }

    return JoinString(VString, " ");
}

int main()
{
    string S1 = "Welcom To Pk , Pk is nice Country\n";
    string StringToReplace = "pk";
    string ReplaceTo = "KSA";

    cout << "Original String:\n"
         << S1;

    cout << "\nReplace With Match Case:\n";
    cout << ReplaceWordInStringUsingSplit(
        S1,
        StringToReplace,
        ReplaceTo);

    cout << "\nReplace Without Match Case:\n";
    cout << ReplaceWordInStringUsingSplit(
        S1,
        StringToReplace,
        ReplaceTo,
        false);

    return 0;
}
