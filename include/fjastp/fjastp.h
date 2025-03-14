#pragma once

namespace FJASTP{
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
    };

    enum class ParserError{
        Success=0
    };
}