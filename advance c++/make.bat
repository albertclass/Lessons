@echo off
set build_tool="C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise\VC\Auxiliary\Build\vcvars64.bat"

chcp 65001 >nul

call %build_tool%

nmake %*