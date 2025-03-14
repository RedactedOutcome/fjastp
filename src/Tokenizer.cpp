#include "pch.h"
#include "Tokenizer.h"

namespace FJASTP{

    TokenizeResult Tokenizer::Tokenize(const HBuffer& input, std::vector<Token>& output) noexcept{
        m_CurrentInput = input;
        m_CurrentOutput = &output;

        m_InputSize = input.GetSize();

        while(true){
            if(m_At >= m_InputSize)return TokenizeResult();
            char c = input.At(m_At);
            
            switch(c){
                case ' ':
                    m_At++;
                    continue;
                case '\n':
                    m_Line++;
                    m_CurrentLineStart=m_At++;
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
                case 'z':
                case '_':{
                    //Is valid Identifier Start
                    TokenizeResult result = ParseIdentifier(c);
                    if(!result)return result;
                    break;
                }
                default:
                    if(c & 0b10000000){
                        TokenizeResult result = ParseIdentifier(c);
                        if(!result)return result;
                        continue;
                    }
                    return TokenizeResult(m_Line, GetCurrentColumn(), TokenizerError::UnsupportedToken);
                }
        }

        return TokenizeResult();
    }

    TokenizeResult Tokenizer::ValidateUTF8() noexcept{
        //Unicode character
        char startChar = m_CurrentInput.At(m_At);
        int8_t bytes;
        if((startChar & 0b11100000) == 0b11000000)
            bytes = 2;
        else if((startChar & 0b11110000) == 0b11100000)
            bytes = 3;
        else if((startChar & 0b11111000) == 0b11110000)
            bytes = 4;
        else
            return TokenizeResult(m_Line, GetCurrentColumn(), TokenizerError::UnsupportedToken);
        if(m_At + bytes >= m_InputSize)return TokenizeResult(m_Line, GetCurrentColumn(), TokenizerError::EndOfFile);

        uint32_t character = startChar & ((2 ^ (8 - bytes))- 1);
        size_t startAt = m_At;

        for(uint8_t i = 1; i < bytes; i++){
            character<<=6;
            uint8_t currentByte = m_CurrentInput.At(++m_At);
            if((currentByte & 0b11000000) != 0b10000000)
                return TokenizeResult(m_Line, GetCurrentColumn(startAt), TokenizerError::InvalidUTF8Character);
            
            character |= (currentByte & 0b111111);
        }
        m_At++;
        m_UnicodeBytesInLine+=bytes;

        bool valid = (character >= 0x80 && character <= 0x7FF) || ((character >= 0x800 && character <= 0xFFFF) && character != 0xD800 && character != 0xDFFF) || (character >= 0x10000 && character <= 0x10FFFF);
        return valid ? TokenizeResult() : TokenizeResult(m_Line, GetCurrentColumn(), TokenizerError::InvalidUTF8Character);
    }

    TokenizeResult Tokenizer::ParseIdentifier(char startChar) noexcept{
        size_t startAt = m_At;

        if(startChar & 128){
            TokenizeResult result = ValidateUTF8();
            if(!result)return result;
        }
        m_At++;
        while(true){
            if(m_At >= m_InputSize)break;
            char c = m_CurrentInput.At(m_At);
            if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '_' || c == '$'){
                m_At++;
                continue;
            }

            if(c & 0b10000000){
                TokenizeResult result = ValidateUTF8();
                if(!result)return result;
            }
            break;
        }
        
        size_t identifierSize = (m_At - startAt);
        HBuffer buff = m_CurrentInput.SubBuffer(startAt, identifierSize);
        m_CurrentOutput->emplace_back(Token(TokenType::Identifier, std::move(buff), m_Line, GetCurrentColumn(startAt)));
        //Success no need to return anything
        return TokenizeResult();
    }
}