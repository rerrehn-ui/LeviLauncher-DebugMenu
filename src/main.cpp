#include <pl/Mod.hpp>
#include <pl/ModMenu.hpp>

class LeviDebugMenu {
public:
    static LeviDebugMenu& instance() {
        static LeviDebugMenu mod;
        return mod;
    }

    LeviDebugMenu()
        : mSelf(*ll::mod::NativeMod::current()) {}

    [[nodiscard]]
    ll::mod::NativeMod& getSelf() const {
        return mSelf;
    }

    bool load() {
        getSelf().getLogger().info(
            "Levi Debug Menu loaded"
        );

        return true;
    }

    bool enable() {
        return pl::modmenu::ModuleBuilder(
            "levi_debug_menu.overlay",
            "Java Debug Menu"
        )
            .modId(getSelf().getId())
            .description(
                "Minecraft Java Edition style debug menu"
            )
            .defaultEnabled(true)
            .registerModule();
    }

private:
    ll::mod::NativeMod& mSelf;
};

PL_REGISTER_MOD(
    LeviDebugMenu,
    LeviDebugMenu::instance()
)
