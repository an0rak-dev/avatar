@echo off

set BIN_DIR=bin
set LIB_DIR=lib\dynamics
set DEBUG_DIR=%BIN_DIR%\debug

rem Make sure that the output directory exists
if not exist "%BIN_DIR%" mkdir %BIN_DIR%
if not exist "%DEBUG_DIR%" mkdir %DEBUG_DIR%

COPY /Y/B %LIB_DIR%\* %DEBUG_DIR%\
