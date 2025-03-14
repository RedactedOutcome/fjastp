#include "pch.h"
#include "Token.h"

namespace FJASTP{
    Token::Token(TokenType type, const HBuffer& value, size_t lineNumber, size_t columnNumber) noexcept
        : m_Type(type), m_Value(value), m_Metadata(0), m_LineNumber(lineNumber), m_ColumnNumber(columnNumber){}
    Token::Token(TokenType type, const HBuffer& value, uint8_t metadata, size_t lineNumber, size_t columnNumber) noexcept
        : m_Type(type), m_Value(value), m_Metadata(metadata), m_LineNumber(lineNumber), m_ColumnNumber(columnNumber){}
    Token::Token(TokenType type, HBuffer&& value, size_t lineNumber, size_t columnNumber) noexcept
        : m_Type(type), m_Value(value), m_Metadata(0), m_LineNumber(lineNumber), m_ColumnNumber(columnNumber){}
    Token::Token(TokenType type, HBuffer&& value, uint8_t metadata, size_t lineNumber, size_t columnNumber) noexcept
        : m_Type(type), m_Value(value), m_Metadata(metadata), m_LineNumber(lineNumber), m_ColumnNumber(columnNumber){}
}