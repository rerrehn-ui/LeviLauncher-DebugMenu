#include <pl/Mod.hpp>
#include <pl/ModMenu.hpp>

#include <vector>
#include <string>

class LeviDebugMenu {
public:
    static LeviDebugMenu& instance() {
        static LeviDebugMenu mod;
        return mod;
    }

    LeviDebugMenu()
        : mSelf(*ll::mod::NativeMod::current()) {}

    ll::mod::NativeMod& getSelf() const {
        return mSelf;
    }

    bool load() {
        getSelf().getLogger().info(
            "Java Debug Menu loaded"
        );

        return true;
    }

    bool enable() {
        return pl::modmenu::ModuleBuilder(
            "levi_debug_menu.overlay",
            "Java Debug Menu"
        )
            .modId(getSelf().getId())
            .description("Java Edition style debug overlay")
            .defaultEnabled(true)
            .onToggle(
                [](std::string_view, bool enabled) {
                    if (enabled) {
                        drawOverlay();
                    } else {
                        clearOverlay();
                    }
                }
            )
            .registerModule();
    }

private:
    static void drawOverlay() {
        
        instance().getSelf().getLogger().info("drawOverlay called");
        
        using namespace pl::modmenu;

        const std::vector<DrawCommand> commands = {
            {
                .type = DrawCommandType::RectFilled,
                .x = 8.0f,
                .y = 8.0f,
                .w = 420.0f,
                .h = 220.0f,
                .color = 0xAA000000
            },
            {
                .type = DrawCommandType::Text,
                .x = 16.0f,
                .y = 16.0f,
                .color = 0xFFFFFFFF,
                .size = 20.0f,
                .text = "Debug Screen"
            },
            {
                .type = DrawCommandType::Text,
                .x = 16.0f,
                .y = 42.0f,
                .color = 0xFFFFFFFF,
                .size = 16.0f,
                .text = "FPS: Waiting for game data"
            },
            {
                .type = DrawCommandType::Text,
                .x = 16.0f,
                .y = 62.0f,
                .color = 0xFFFFFFFF,
                .size = 13.0f,
                .text = "XYZ: Waiting for game data"
            },
            {
                .type = DrawCommandType::Text,
                .x = 16.0f,
                .y = 82.0f,
                .color = 0xFFFFFFFF,
                .size = 16.0f,
                .text = "Facing: Waiting for game data"
            },
            {
                .type = DrawCommandType::Text,
                .x = 16.0f,
                .y = 102.0f,
                .color = 0xFFFFFFFF,
                .size = 16.0f,
                .text = "Biome: Waiting for game data"
            }
        };

        submitDrawCommands(
            "levi_debug_menu.overlay",
            commands
        );
    }

    static void clearOverlay() {
        pl::modmenu::submitDrawCommands(
            "levi_debug_menu.overlay",
            {}
        );
    }

    ll::mod::NativeMod& mSelf;
};

PL_REGISTER_MOD(
    LeviDebugMenu,
    LeviDebugMenu::instance()
)
