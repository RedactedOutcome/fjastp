#include "pch.h"
#include "Token.h"

namespace FJASTP{
    Token::Token(const HBuffer& name, const HBuffer& value, size_t lineNumber, size_t columnNumber) noexcept
        : m_Name(name), m_Value(value), m_LineNumber(lineNumber), m_ColumnNumber(columnNumber){}
    Token::Token(HBuffer&& name, const HBuffer& value, size_t lineNumber, size_t columnNumber) noexcept
        : m_Name(name), m_Value(value), m_LineNumber(lineNumber), m_ColumnNumber(columnNumber){}
    Token::Token(const HBuffer& name, HBuffer&& value, size_t lineNumber, size_t columnNumber) noexcept
        : m_Name(name), m_Value(value), m_LineNumber(lineNumber), m_ColumnNumber(columnNumber){}
    Token::Token(HBuffer&& name, HBuffer&& value, size_t lineNumber, size_t columnNumber) noexcept
        : m_Name(name), m_Value(value), m_LineNumber(lineNumber), m_ColumnNumber(columnNumber){}
}