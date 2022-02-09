#include <iostream>
#include "md2formspec.h"

extern "C" {
    #include "lua.h"
    #include "lauxlib.h"
    #include "lualib.h"
}

char text[] = R"(
# -1
## -2
### -3
#### -4
##### -5
###### -6

Test.
)";

int main() {
    lua_State* L;

    // initialize Lua interpreter
    L = luaL_newstate();

    luaL_openlibs(L);

    auto ret = luaL_dofile(L, "run.lua");

    if (ret != 0) {
        printf("LUA error: %s", lua_tostring(L, -1));
    }

    md_parse(text, sizeof(text), &md2f, nullptr);

    return 0;
}