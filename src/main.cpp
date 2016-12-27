#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


extern "C"
{
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
#include "md5.h"
}

using namespace std;
/*
 
	   source code
	   md5：
	   http://keplerproject.github.io/md5/
	   https://github.com/shanhai2015/md5
	   Lua 5.3.3：http://www.lua.org/download.html

*/

int
lua_get_key(char *url, char *buf,const char * script_name)
{
    lua_State *L = luaL_newstate();
    int i = 0;
    const char *p = NULL;
    time_t  cur, endtime;
   // char * script_name="getkey.lua"

    luaL_openlibs(L);

    lua_register(L, "LOCMD5", lmd5);
    printf("load lua:%s\n", script_name);
    int err = luaL_dofile(L, script_name);
    //int err = luaL_dostring(L, luastring);
    if (err){
        printf("load lua error\n");
        return 0;
    }

    lua_getglobal(L, "getKey");
    lua_pushstring(L, url);
    err = lua_pcall(L, 1, 1, 0);
    if (err) {
        printf("lua:%s\n", lua_tostring(L, -1));
        lua_pop(L, 1);
        return 0;
    }

    p = lua_tostring(L, -1);
    if (p) {
        strncpy(buf, p, strlen(p));
    }
    lua_pop(L, 1);
    lua_close(L);
    return strlen(buf);
}

int main() {
    cout << "Hello, World!" << endl;
    const char * url="http://www.baidu.com";
    const char * scriptname="lua_url_md5.lua";
    char buf[512]={0};
    int ret=0;
    ret =lua_get_key((char*)url,buf,scriptname);
    if(ret>0){
        cout<<"Url:"<<url<<endl;
        cout<<"MD5key:"<<buf<<endl;
    } else{
        cout<<"Url:"<<url<<endl;
        cout<<"Not get MD5key:"<<buf<<endl;
    }

    return 0;
}
