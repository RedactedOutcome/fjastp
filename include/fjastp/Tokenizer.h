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
        [[nodiscard]] TokenizeResult Tokenize(const HBuffer& input, std::vector<Token>& output) noexcept;
    };
}