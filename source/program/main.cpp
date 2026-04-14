#include "lib.hpp"

// autosave offset for ver 2.0.2
static constexpr ptrdiff_t AUTOSAVE_OFFSET = 0x92D0A8;

// hook declaration
/*HOOK_DEFINE_INLINE(DisableAutosaveHook) {
    static void Callback(exl::hook::nx64::InlineCtx* ctx) {
        // OG  : mov w8,#0x1
        // new : mov w8,#0x0
        ctx->W[8] = 0;
    }
};*/

extern "C" void exl_main(void* x0, void* x1) {
    exl::hook::Initialize();

    exl::patch::CodePatcher patcher(AUTOSAVE_OFFSET);

    // Applique le patch
    patcher.Write(0x3903E27F);

    //DisableAutosaveHook::InstallAtOffset(AUTOSAVE_OFFSET);
}