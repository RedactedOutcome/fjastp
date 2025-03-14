#include "pch.h"
#include "FJASTP/FJASTP.h"

namespace FJASTP{
    std::unordered_map<HBuffer, bool> FJASTP::s_Keywords;

    InitializationResult FJASTP::Init() noexcept{
        s_Keywords.insert(std::make_pair<HBuffer, bool>(HBuffer("await"), true));
        s_Keywords.insert(std::make_pair<HBuffer, bool>(HBuffer("break"), true));
        s_Keywords.insert(std::make_pair<HBuffer, bool>(HBuffer("case"), true));
        s_Keywords.insert(std::make_pair<HBuffer, bool>(HBuffer("catch"), true));
        s_Keywords.insert(std::make_pair<HBuffer, bool>(HBuffer("class"), true));
        s_Keywords.insert(std::make_pair<HBuffer, bool>(HBuffer("const"), true));
        s_Keywords.insert(std::make_pair<HBuffer, bool>(HBuffer("continue"), true));
        s_Keywords.insert(std::make_pair<HBuffer, bool>(HBuffer("debugger"), true));
        s_Keywords.insert(std::make_pair<HBuffer, bool>(HBuffer("default"), true));
        s_Keywords.insert(std::make_pair<HBuffer, bool>(HBuffer("delete"), true));
        s_Keywords.insert(std::make_pair<HBuffer, bool>(HBuffer("do"), true));
        s_Keywords.insert(std::make_pair<HBuffer, bool>(HBuffer("else"), true));
        s_Keywords.insert(std::make_pair<HBuffer, bool>(HBuffer("export"), true));
        s_Keywords.insert(std::make_pair<HBuffer, bool>(HBuffer("extends"), true));
        s_Keywords.insert(std::make_pair<HBuffer, bool>(HBuffer("finally"), true));
        s_Keywords.insert(std::make_pair<HBuffer, bool>(HBuffer("for"), true));
        s_Keywords.insert(std::make_pair<HBuffer, bool>(HBuffer("function"), true));
        s_Keywords.insert(std::make_pair<HBuffer, bool>(HBuffer("if"), true));
        s_Keywords.insert(std::make_pair<HBuffer, bool>(HBuffer("import"), true));
        s_Keywords.insert(std::make_pair<HBuffer, bool>(HBuffer("in"), true));
        s_Keywords.insert(std::make_pair<HBuffer, bool>(HBuffer("instanceof"), true));
        s_Keywords.insert(std::make_pair<HBuffer, bool>(HBuffer("let"), true));
        s_Keywords.insert(std::make_pair<HBuffer, bool>(HBuffer("new"), true));
        s_Keywords.insert(std::make_pair<HBuffer, bool>(HBuffer("return"), true));
        s_Keywords.insert(std::make_pair<HBuffer, bool>(HBuffer("super"), true));
        s_Keywords.insert(std::make_pair<HBuffer, bool>(HBuffer("switch"), true));
        s_Keywords.insert(std::make_pair<HBuffer, bool>(HBuffer("this"), true));
        s_Keywords.insert(std::make_pair<HBuffer, bool>(HBuffer("throw"), true));
        s_Keywords.insert(std::make_pair<HBuffer, bool>(HBuffer("try"), true));
        s_Keywords.insert(std::make_pair<HBuffer, bool>(HBuffer("typeof"), true));
        s_Keywords.insert(std::make_pair<HBuffer, bool>(HBuffer("var"), true));
        s_Keywords.insert(std::make_pair<HBuffer, bool>(HBuffer("void"), true));
        s_Keywords.insert(std::make_pair<HBuffer, bool>(HBuffer("while"), true));
        s_Keywords.insert(std::make_pair<HBuffer, bool>(HBuffer("with"), true));
        s_Keywords.insert(std::make_pair<HBuffer, bool>(HBuffer("yield"), true));
        return InitializationResult::Success;
    }
}