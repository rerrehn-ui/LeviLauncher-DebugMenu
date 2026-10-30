#include <pl/Mod.hpp>
#include <pl/Logger.hpp>

class DebugMenuMod {
public:
    bool load() {
        auto* mod = pl::mod::NativeMod::current();

        if (mod != nullptr) {
            mod->getLogger().info(
                "Java Debug Menu loaded"
            );
        }

        return true;
    }
};

PL_REGISTER_MOD(
    DebugMenuMod,
    DebugMenuMod{}
)
