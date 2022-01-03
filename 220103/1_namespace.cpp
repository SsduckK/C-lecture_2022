//md-2-1. namespace.cpp
#include <iostream>

namespace Audio
{
    void init() {std::cout << "Audio::init" << std::endl;}
}

namespace Video
{
    void init() {std::cout << "video::init" << std::endl;}
}

void init()
{
    std::cout << "Global init" << std::endl;
}

int main()
{
    Audio::init();
    Video::init();
    
    init();
}