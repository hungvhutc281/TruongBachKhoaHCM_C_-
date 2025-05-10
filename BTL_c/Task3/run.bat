@echo off
setlocal enabledelayedexpansion

g++ -std=c++17 -o main -Iinclude -Itest -Itest\unit_test_Task3 main.cpp ^
test\unit_test_Task3\unit_test_Task3.cpp test\unit_test.cpp ^
src\Position.cpp src\Unit.cpp src\Vehicle.cpp src\Infantry.cpp ^
src\Army.cpp src\UnitList.cpp src\LiberationArmy.cpp src\ARVN.cpp ^
src\BattleField.cpp src\Configuration.cpp src\TerrainElement.cpp ^
test\unit_test_Task3\test_case\Task301.cpp ^
test\unit_test_Task3\test_case\Task302.cpp ^
test\unit_test_Task3\test_case\Task303.cpp ^
test\unit_test_Task3\test_case\Task304.cpp ^
test\unit_test_Task3\test_case\Task305.cpp ^
test\unit_test_Task3\test_case\Task306.cpp ^
test\unit_test_Task3\test_case\Task307.cpp ^
test\unit_test_Task3\test_case\Task308.cpp ^
test\unit_test_Task3\test_case\Task309.cpp ^
test\unit_test_Task3\test_case\Task310.cpp ^
test\unit_test_Task3\test_case\Task311.cpp ^
test\unit_test_Task3\test_case\Task312.cpp ^
test\unit_test_Task3\test_case\Task313.cpp ^
test\unit_test_Task3\test_case\Task314.cpp ^
test\unit_test_Task3\test_case\Task315.cpp ^
test\unit_test_Task3\test_case\Task316.cpp ^
test\unit_test_Task3\test_case\Task317.cpp ^
test\unit_test_Task3\test_case\Task318.cpp ^
test\unit_test_Task3\test_case\Task319.cpp ^
test\unit_test_Task3\test_case\Task320.cpp ^
test\unit_test_Task3\test_case\Task321.cpp ^
test\unit_test_Task3\test_case\Task322.cpp ^
test\unit_test_Task3\test_case\Task323.cpp ^
test\unit_test_Task3\test_case\Task324.cpp ^
test\unit_test_Task3\test_case\Task325.cpp ^
test\unit_test_Task3\test_case\Task326.cpp ^
test\unit_test_Task3\test_case\Task327.cpp ^
test\unit_test_Task3\test_case\Task328.cpp ^
test\unit_test_Task3\test_case\Task329.cpp ^
test\unit_test_Task3\test_case\Task330.cpp ^
test\unit_test_Task3\test_case\Task331.cpp ^
test\unit_test_Task3\test_case\Task332.cpp ^
test\unit_test_Task3\test_case\Task333.cpp ^
test\unit_test_Task3\test_case\Task334.cpp ^
test\unit_test_Task3\test_case\Task335.cpp ^
test\unit_test_Task3\test_case\testTask2.cpp

if %ERRORLEVEL% equ 0 (
    echo Build successful!
    echo ----------------------------------------
    echo To run tests, use one of the following commands:
    echo 1. Run all tests: .\main
    echo 2. Run a specific test: .\main nameFunctionUnitTest
) else (
    echo Build failed!
    exit /b 1
)