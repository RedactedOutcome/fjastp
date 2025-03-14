#pragma once

#ifdef FJASTP_USE_PCH
#include FJASTP_PCH_DIR
#else
#include <HBuffer/HBuffer.hpp>
#include <cstdint>
#endif

#include "FJASTP.h"

namespace FJASTP{
    class Token{
    public:
        Token(TokenType type, const HBuffer& value, size_t lineNumber, size_t columnNumber) noexcept;
        Token(TokenType type, HBuffer&& value, size_t lineNumber, size_t columnNumber) noexcept;

        TokenType GetType() const noexcept{return (TokenType)m_Type;}
        HBuffer& GetValue() const noexcept{return (HBuffer&)m_Value;}
        size_t GetLineNumber() const noexcept{return m_LineNumber;}
        size_t GetColumnNumber() const noexcept{return m_ColumnNumber;}
    private:
        TokenType m_Type;
        HBuffer m_Value;
        size_t m_LineNumber;
        size_t m_ColumnNumber;
    };
}