#pragma once

// 常规标准头，兼容 MSVC 和 GCC/Clang
//#include <bits/stdc++.h> // 如果使用 MSVC 且不安装 libstdc++，请删除这一行并使用下面注释掉的头
 #include <iostream>
 #include <vector>
 #include <algorithm>
 #include <string>
 #include <map>
 #include <set>
 #include <queue>
 #include <stack>
 #include <cmath>
 #include <numeric>

using namespace std;

// 快速 IO
struct FastIO {
    FastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }
} fast_io_init;

// 调试时重定向到本地文件（仅在 Debug 定义时生效）
inline void debug_redirect_stdio_once() {
#ifdef _DEBUG
    static bool done = false;
    if (!done) {
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
        done = true;
    }
#endif
}

// 常用小工具
template <class T> inline void chmax(T& a, const T& b) { if (b > a) a = b; }
template <class T> inline void chmin(T& a, const T& b) { if (b < a) a = b; }
