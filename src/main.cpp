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


int
vod_2_lua_getkey(char *url, char *buf, int *keylen, char *version, int *verlen,const char * script_name)
{/*
	lua script	return two result
*/
    lua_State       *L = luaL_newstate();
    time_t                cur, endtime;
    const   char    *p = NULL;
    int              i = 0;

    if (!url || !buf || !keylen || !version || !verlen) return 0;
    luaL_openlibs(L);
    lua_register(L, "LOCMD5", lmd5);
    printf("load lua:%s", script_name);
    int err = luaL_dofile(L, script_name);
    if (err){
        printf("load lua error");
        return 0;
    }

    lua_getglobal(L, "getKey2");
    lua_pushstring(L, url);
    err = lua_pcall(L, 1, 2, 0);
    if (err) {
        printf("lua:%s\n", lua_tostring(L, -1));
        lua_pop(L, 1);
        return 0;
    }

    //lua_pop(L, 1);
    p = lua_tostring(L, -1);
    if (p) {
        strncpy(version, p, strlen(p));
        *verlen = strlen(version);
    }

    p = lua_tostring(L, -2);
    if (p) {
        strncpy(buf, p, strlen(p));
        *keylen = strlen(buf);
    }

    printf("luag get key:%s, version:%s\n", buf, version);
    lua_close(L);
    return strlen(buf);
}


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
    char urlkey[512]={0};
    char urlver[128]={0};
    int keylen = 0;
    int verlen = 0;
    int ret=0;
    ret =lua_get_key((char*)url,urlkey,scriptname);
    if(ret>0){
        cout<<"Url:"<<url<<endl;
        cout<<"MD5key:"<<urlkey<<endl;
    } else{
        cout<<"Url:"<<url<<endl;
        cout<<"Not get MD5key:"<<urlkey<<endl;
    }
    cout<<"----------------------------------------"<<endl;
    ret = vod_2_lua_getkey((char*)url,urlkey,&keylen,urlver,&verlen,scriptname);
    if(ret>0){
        cout<<"Url:"<<url<<endl;
        cout<<"MD5key:"<<urlkey<<endl;
        cout<<"version:"<<urlver<<endl;
    } else{
        cout<<"Url:"<<url<<endl;
        cout<<"Not get MD5key:"<<urlkey<<endl;
    }
    return 0;
}