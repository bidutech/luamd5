
# cmake_minimum_required(VERSION <specify CMake version here>)
cmake_minimum_required(VERSION 3.5)
project(luaMd5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/lua/src/lapi.c
    src/lua/src/lapi.h
    src/lua/src/lauxlib.c
    src/lua/src/lauxlib.h
    src/lua/src/lbaselib.c
    src/lua/src/lbitlib.c
    src/lua/src/lcode.c
    src/lua/src/lcode.h
    src/lua/src/lcorolib.c
    src/lua/src/lctype.c
    src/lua/src/lctype.h
    src/lua/src/ldblib.c
    src/lua/src/ldebug.c
    src/lua/src/ldebug.h
    src/lua/src/ldo.c
    src/lua/src/ldo.h
    src/lua/src/ldump.c
    src/lua/src/lfunc.c
    src/lua/src/lfunc.h
    src/lua/src/lgc.c
    src/lua/src/lgc.h
    src/lua/src/linit.c
    src/lua/src/liolib.c
    src/lua/src/llex.c
    src/lua/src/llex.h
    src/lua/src/llimits.h
    src/lua/src/lmathlib.c
    src/lua/src/lmem.c
    src/lua/src/lmem.h
    src/lua/src/loadlib.c
    src/lua/src/lobject.c
    src/lua/src/lobject.h
    src/lua/src/lopcodes.c
    src/lua/src/lopcodes.h
    src/lua/src/loslib.c
    src/lua/src/lparser.c
    src/lua/src/lparser.h
    src/lua/src/lprefix.h
    src/lua/src/lstate.c
    src/lua/src/lstate.h
    src/lua/src/lstring.c
    src/lua/src/lstring.h
    src/lua/src/lstrlib.c
    src/lua/src/ltable.c
    src/lua/src/ltable.h
    src/lua/src/ltablib.c
    src/lua/src/ltm.c
    src/lua/src/ltm.h
    src/lua/src/lua.c
    src/lua/src/lua.h
    src/lua/src/lua.hpp
    src/lua/src/luac.c
    src/lua/src/luaconf.h
    src/lua/src/lualib.h
    src/lua/src/lundump.c
    src/lua/src/lundump.h
    src/lua/src/lutf8lib.c
    src/lua/src/lvm.c
    src/lua/src/lvm.h
    src/lua/src/lzio.c
    src/lua/src/lzio.h
    src/luamd5/src/compat-5.2.c
    src/luamd5/src/compat-5.2.h
    src/luamd5/src/des56.c
    src/luamd5/src/des56.h
    src/luamd5/src/ldes56.c
    src/luamd5/src/ldes56.h
    src/luamd5/src/md5.c
    src/luamd5/src/md5.h
    src/luamd5/src/md5lib.c

    src/main.cpp)

SET(LUAINCLUDE  src/lua/src/)
SET(LUAMD5INCLUDE   src/luamd5/src)

INCLUDE_DIRECTORIES(${LUAINCLUDE} ${LUAMD5INCLUDE})


add_executable(luaMd5 ${SOURCE_FILES})
