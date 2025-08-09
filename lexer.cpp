#include <string>

enum Token // enum to represent the different possible values
{
    tok_eof = -1,
    tok_def = -2,
    tok_extern = -3,
    tok_identifier = -4,
    tok_number = -5
};

static std::string IdentifierStr; // to store identifier name if tok_identifier
static double numVal;             // to store value of number of tok_number

static int gettok() // main function that implements the lexer
{
    static int LastChar = ' ';

    while (isspace(LastChar))
        LastChar = getchar(); // to ignore whitespaces between tokens

    if (isalpha(LastChar))
    {
        IdentifierStr = LastChar;
        while (isalnum(LastChar = getchar()))
        {
            IdentifierStr += LastChar;
        }
    }
}