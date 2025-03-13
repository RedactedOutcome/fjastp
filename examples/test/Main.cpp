#include "pch.h"

#include <filesystem>
#include <fstream>

#include "FJASTP.h"
#include "FJASTP/Tokenizer.h"

int main(int argc, char** argv){
    std::cout<<"Hello World"<<std::endl;
    HBuffer test1;

    if(argc <= 1){
        std::ifstream file("examples/test/res/test1.js", std::ios::binary);
        if(!file){
            std::cout << "Failed to open file res/test1.js"<<std::endl;
            return -1;
        }

        file.seekg(std::ios::beg);
        size_t len = file.tellg();
        file.seekg(std::ios::end);

        char* data = new char[len];
        std::filebuf* buf = file.rdbuf();
        buf->sgetn(data, len);
        test1 = HBuffer(data, len, true, true);
    }else{
        test1 = argv[1];
    }

    std::cout << "Starting"<<std::endl;
    FJASTP::Tokenizer t;
    int status = t.Tokenize(test1);
    std::cout << "Tokenize status is " << status<<std::endl;
}