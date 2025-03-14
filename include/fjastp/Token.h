#pragma once

#ifdef FJASTP_USE_PCH
#include FJASTP_PCH_DIR
#else
#include <HBuffer/HBuffer.hpp>
#include <cstdint>
#endif

#include "FJASTP.h"

namespace FJASTP{
    /// @brief A class for storing javascript tokens.
    class Token{
    public:
        Token(TokenType type, const HBuffer& value, size_t lineNumber, size_t columnNumber) noexcept;
        Token(TokenType type, const HBuffer& value, uint8_t metadata, size_t lineNumber, size_t columnNumber) noexcept;
        Token(TokenType type, HBuffer&& value, size_t lineNumber, size_t columnNumber) noexcept;
        Token(TokenType type, HBuffer&& value, uint8_t metadata, size_t lineNumber, size_t columnNumber) noexcept;

        TokenType GetType() const noexcept{return (TokenType)m_Type;}
        HBuffer& GetValue() const noexcept{return (HBuffer&)m_Value;}
        uint8_t GetMetadata() const noexcept{return (uint8_t)m_Metadata;}
        size_t GetLineNumber() const noexcept{return m_LineNumber;}
        size_t GetColumnNumber() const noexcept{return m_ColumnNumber;}
    private:
        TokenType m_Type;
        HBuffer m_Value;
        /// @brief stores extra metadata that is interpreted differently depending on the tokenType
        uint8_t m_Metadata;
        size_t m_LineNumber;
        size_t m_ColumnNumber;
    };
}