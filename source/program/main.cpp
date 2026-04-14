#include "lib.hpp"

// autosave offset for ver 2.0.2
static constexpr ptrdiff_t AUTOSAVE_OFFSET = 0x92D0A8;


extern "C" void exl_main(void* x0, void* x1) {
    exl::hook::Initialize();

    exl::patch::CodePatcher patcher(AUTOSAVE_OFFSET);

    patcher.Write(0x3903E27F);
}