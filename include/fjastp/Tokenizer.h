#pragma once

#ifdef FJASTP_USE_PCH
#include FJASTP_PCH_DIR
#else
#include <HBuffer/HBuffer.hpp>
#include <vector>
#endif

#include "FJASTP.h"
#include "Token.h"

namespace FJASTP{
    struct TokenizeResult{
        size_t m_Line;
        size_t m_Column;
        TokenizerError m_ErrorCode;    //Type of TokenizerError

        TokenizeResult() noexcept: m_Line(0), m_Column(0), m_ErrorCode(TokenizerError::Success){}
        TokenizeResult(size_t line, size_t column, TokenizerError errorCode) noexcept: m_Line(line), m_Column(column), m_ErrorCode(errorCode){}

        constexpr operator bool() const noexcept{
            return m_ErrorCode == TokenizerError::Success;
        }
    };

    class Tokenizer{
    public:
        /// @brief Parses the input file as javascript and appends tokens to output
        [[nodiscard]] TokenizeResult Tokenize(const HBuffer& input, std::vector<Token>& output) noexcept;
    private:
        /// @brief Starts parsing the characters into a identifier token
        TokenizeResult ParseIdentifier(size_t at)noexcept;

        size_t GetCurrentColumn() const noexcept{return (m_At - m_CurrentLineStart - m_UnicodeBytesInLine) + 1;}
    private:
        size_t m_At = 0;
        size_t m_Line = 1;     //What line the tokenizer is currently on
        size_t m_CurrentLineStart=0;    //Determines where the current line started in the buffer to calculate the column
        size_t m_UnicodeBytesInLine=0;    //Determines where the current line started in the buffer to calculate the column
        HBuffer m_CurrentInput;
        size_t m_InputSize;
        std::vector<Token>* m_CurrentOutput = nullptr;
    };
}