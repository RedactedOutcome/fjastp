#include "pch.h"
#include "Tokenizer.h"

namespace FJASTP{

    TokenizeResult Tokenizer::Tokenize(const HBuffer& input, std::vector<Token>& output) noexcept{
        m_CurrentInput = input;
        m_CurrentOutput = &output;

        m_InputSize = input.GetSize();

        for(m_At = 0; m_At < m_InputSize; m_At++){
            char c = input.At(m_At);

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
                TokenizeResult result = ParseIdentifier(m_At);
                if(!result)return result;
                break;
            }
            default:
                if(c > 127){
                    size_t startAt = m_At;

                    //Unicode character
                    int8_t bytes;
                    if((c & 0b11100000) == 0b11000000)
                        bytes = 2;
                    else if((c & 0b11110000) == 0b11100000)
                        bytes = 3;
                    else if((c & 0b11111000) == 0b11110000)
                        bytes = 4;
                    else
                        return TokenizeResult(m_Line, GetCurrentColumn(), TokenizerError::UnsupportedToken);
                    if(m_At + bytes >= m_InputSize)return TokenizeResult(m_Line, GetCurrentColumn(), TokenizerError::EndOfFile);
                    m_UnicodeBytesInLine+=bytes;
                    uint32_t character = 0;
                    while(bytes > 0){
                        character<<=8;
                        character|=input.At(m_At++);
                        bytes--;
                    }

                    TokenizeResult result = ParseIdentifier(startAt);
                    if(!result)return result;
                }
                return TokenizeResult(m_Line, GetCurrentColumn(), TokenizerError::UnsupportedToken);
            }
        }
        return TokenizeResult();
    }

    TokenizeResult Tokenizer::ParseIdentifier(size_t at) noexcept{
        
    }
}