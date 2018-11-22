
@echo off

set AABCD=hello_blue

echo %AABCD% | findstr "blue"
if not errorlevel 1 (
  echo blue found
)

pause
