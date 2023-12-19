#include <iostream>
#include <map>
#include <set>
using namespace std;

const int MAX_RULES = 10;
const int MAX_RULE_LENGTH = 10;

// Function to find the FIRST of non-terminals
void findFirst(char nonTerminal, char grammar[MAX_RULES][MAX_RULE_LENGTH], int ruleCount, map<char, set<char>> &firstSet)
{
    // If FIRST set for this non-terminal is already computed, return it
    if (firstSet.find(nonTerminal) != firstSet.end())
    {
        return;
    }

    set<char> first;

    for (int i = 0; i < ruleCount; ++i)
    {
        if (grammar[i][0] == nonTerminal)
        {
            char symbol = grammar[i][2];

            if (isupper(symbol))
            {
                // If it's a non-terminal, recursively find its FIRST set
                findFirst(symbol, grammar, ruleCount, firstSet);

                // Add all symbols from FIRST set of the non-terminal
                first.insert(firstSet[symbol].begin(), firstSet[symbol].end());
            }
            else
            {
                // If it's a terminal, add it to the FIRST set
                first.insert(symbol);
            }
        }
    }

    // Cache the computed FIRST set for this non-terminal
    firstSet[nonTerminal] = first;
}

int main()
{
    int ruleCount;

    cout << "Enter the number of rules: ";
    cin >> ruleCount;

    char grammar[MAX_RULES][MAX_RULE_LENGTH];

    cout << "Enter the grammar rules (e.g., S=aA, A=bB, A=ε):" << endl;
    for (int i = 0; i < ruleCount; ++i)
    {
        cin >> grammar[i];
    }

    // Map to store computed FIRST sets
    map<char, set<char>> firstSet;

    // Find the FIRST set of a specified non-terminal
    char startSymbol;
    cout << "Enter the non-terminal to find FIRST set: ";
    cin >> startSymbol;

    findFirst(startSymbol, grammar, ruleCount, firstSet);

    // Display the result
    cout << "FIRST set of non-terminal " << startSymbol << ": { ";
    for (char symbol : firstSet[startSymbol])
    {
        cout << symbol << " ";
    }
    cout << "}" << endl;

    return 0;
}