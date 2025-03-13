#pragma once

namespace FJASTP{
    enum class TokenizerError{
        Success=0,
        EndOfFile,
        UnsupportedToken,
    };

    enum class ParserError{
        Success=0
    };
}