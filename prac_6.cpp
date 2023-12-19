#include <iostream>
using namespace std;

const int MAX_RULES = 10;

// Function to find the leading of non-terminals
void findLeading(char nonTerminal, char *leading, char grammar[][MAX_RULES][MAX_RULES], int ruleCount)
{
    int leadingIndex = 0;

    for (int i = 0; i < ruleCount; ++i)
    {
        if (grammar[i][0][0] == nonTerminal)
        {
            char symbol = grammar[i][0][2];
            if (isupper(symbol))
            {
                // If it's a non-terminal, recursively find its leading
                findLeading(symbol, leading, grammar, ruleCount);
            }
            else
            {
                // If it's a terminal, add it to the leading array
                leading[leadingIndex++] = symbol;
            }
        }
    }
}

int main()
{
    int ruleCount;
    char grammar[MAX_RULES][MAX_RULES][MAX_RULES];

    cout << "Enter the number of rules: ";
    cin >> ruleCount;

    cout << "Enter the grammar rules (e.g., S=aA, A=bA, A=ε):" << endl;
    for (int i = 0; i < ruleCount; ++i)
    {
        cin >> grammar[i][0];
    }

    // Find the leading of non-terminal 'S'
    char leadingS[MAX_RULES];
    findLeading('S', leadingS, grammar, ruleCount);

    // Display the result
    cout << "Leading of non-terminal S: ";
    for (int i = 0; leadingS[i] != '\0'; ++i)
    {
        cout << leadingS[i] << " ";
    }

    return 0;
}