#pragma once

#ifdef FJASTP_USE_PCH
#include FJASTP_PCH_DIR
#else
#include <unordered_map>
#endif

namespace FJASTP{
    enum class InitializationResult{
        Success=0
    };

    enum class TokenType{
        Identifier,
        Keyword,
        StringLiteral,
        NumericalLiteral,
        BoolLiteral,
        NullLiteral,
        ArithmeticOperator,
        LogicalOperator,
        ConditionalOperator,
        AssignmentOperator,
        BitwiseOperator,
        TernaryOperator,
        Punctuator,
        GroupingSymbol,
        RegExpLiteral,
        TemplateLiteral
    };
    enum class TokenizerError{
        Success=0,
        EndOfFile,
        UnsupportedToken,
        InvalidUTF8Character,
        InvalidNumericalLiteral
    };

    enum class ParserError{
        Success=0
    };

    class FJASTP{
    public:
        static InitializationResult Init() noexcept;

        static bool IsKeyword(const HBuffer& identifier) noexcept{return s_Keywords[identifier];}
    private:
        static std::unordered_map<HBuffer, bool> s_Keywords;
    };
}