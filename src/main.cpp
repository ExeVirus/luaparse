#include <iostream>
#include "md2formspec.h"

#ifdef __cplusplus
extern "C"{
#endif

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

// average can take any number of integer arguments
static int average (lua_State *L) {
	/* get number of arguments */
	int n = lua_gettop(L);
	double sum = 0;
	int i;

	/* loop through each argument */
	for (i = 1; i <= n; i++)
	{
		/* total the arguments */
		sum += lua_tonumber(L, i);
	}

	/* push the average */
	lua_pushnumber(L, sum / n);

	/* push the sum */
	lua_pushnumber(L, sum);

	/* return the number of results */
	return 2;
}

#ifdef __cplusplus
}
#endif

char text[] = R"(
# -1
## -2
### -3
#### -4
##### -5
###### -6

Test.
)";

static int l_sin (lua_State *L) {
    double d = lua_tonumber(L, 1);  /* get argument */
    lua_pushnumber(L, sin(d));  /* push result */
    return 1;  /* number of results */
}

int main() {
    lua_State* L;

    // initialize Lua interpreter
    L = luaL_newstate();

    luaL_openlibs(L);

    lua_pushcfunction(L, average);
    lua_setglobal(L, "average");

    //lua_register(L, "test", average);

    auto ret = luaL_dofile(L, "run.lua");

    if (ret != 0) {
        printf("LUA error: %s", lua_tostring(L, -1));
    }

    md_parse(text, sizeof(text), &md2f, nullptr);

    return 0;
}