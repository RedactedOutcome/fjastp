#pragma once

#ifdef FJASTP_USE_PCH
#include FJASTP_PCH_DIR
#else
#include <HBuffer/HBuffer.hpp>
#include <cstdint>
#endif

namespace FJASTP{
    class Token{
    public:
        Token(const HBuffer& name, const HBuffer& value, size_t lineNumber, size_t columnNumber) noexcept;
        Token(HBuffer&& name, const HBuffer& value, size_t lineNumber, size_t columnNumber) noexcept;
        Token(const HBuffer& name, HBuffer&& value, size_t lineNumber, size_t columnNumber) noexcept;
        Token(HBuffer&& name, HBuffer&& value, size_t lineNumber, size_t columnNumber) noexcept;

        HBuffer& GetName() const noexcept{return (HBuffer&)m_Name;}
        HBuffer& GetValue() const noexcept{return (HBuffer&)m_Value;}
        size_t GetLineNumber() const noexcept{return m_LineNumber;}
        size_t GetColumnNumber() const noexcept{return m_ColumnNumber;}
    private:
        HBuffer m_Name;
        HBuffer m_Value;
        size_t m_LineNumber;
        size_t m_ColumnNumber;
    };
}