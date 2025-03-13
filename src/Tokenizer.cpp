#include "pch.h"
#include "Tokenizer.h"

namespace FJASTP{
    TokenizeResult Tokenizer::Tokenize(const HBuffer& input, std::vector<Token>& output) noexcept{
        size_t inputSize = input.GetSize();

        size_t line = 1;
        size_t lastLineAt = 0; //Used for calculating the column with (at - lastLineAt) + 1
        for(size_t at = 0; at < inputSize; at++){
            char c = input.At(at);

            switch(c){
            case ' ':
                continue;
            case 'A':
            case 'B':
            case 'C':
            case 'D':
            case 'E':
            case 'F':
            case 'G':
            case 'H':
            case 'I':
            case 'J':
            case 'K':
            case 'L':
            case 'M':
            case 'N':
            case 'O':
            case 'P':
            case 'Q':
            case 'R':
            case 'S':
            case 'T':
            case 'U':
            case 'V':
            case 'W':
            case 'X':
            case 'Y':
            case 'Z':
            case 'a':
            case 'b':
            case 'c':
            case 'd':
            case 'e':
            case 'f':
            case 'g':
            case 'h':
            case 'i':
            case 'j':
            case 'k':
            case 'l':
            case 'm':
            case 'n':
            case 'o':
            case 'p':
            case 'q':
            case 'r':
            case 's':
            case 't':
            case 'u':
            case 'v':
            case 'w':
            case 'x':
            case 'y':
            case 'z':{
                //Is valid Identifier Start
                size_t identifierStart = at++;
                while(true){
                    if(at >= inputSize)return TokenizeResult(line, at - lastLineAt + 1, TokenizerError::EndOfFile);
                    c = input.At(at++);
                    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '_' || c ==
                }
                break;
            }
            default:
                return TokenizeResult(line, (at - lastLineAt) + 1, TokenizerError::UnsupportedToken);
            }
        }
        return TokenizeResult();
    }
}