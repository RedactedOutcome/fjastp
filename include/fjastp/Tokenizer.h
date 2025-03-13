#pragma once

#ifdef FJASTP_USE_PCH
#include FJASTP_PCH_DIR
#else
#include <HBuffer/HBuffer.hpp>
#include <vector>
#endif

#include "fjastp.h"

namespace FJP{
    class Tokenizer{
    public:
        int Tokenize(const HBuffer& input) noexcept;
    };
}