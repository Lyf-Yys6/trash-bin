@echo off
:: 切换终端编码为UTF-8
chcp 65001 >nul
echo ==================== 开始编译 ====================
:: UTF-8完整编译命令
g++ todo.cpp -o todo.exe -finput-charset=UTF-8 -fexec-charset=UTF-8
:: 判断编译是否成功
if %errorlevel% equ 0 (
    echo 编译成功，即将运行程序
    echo ==================================================
    todo.exe
) else (
    echo 编译失败，请检查代码语法！
)
echo.
pause