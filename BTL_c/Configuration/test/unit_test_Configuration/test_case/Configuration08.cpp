#include "../unit_test_Configuration.hpp"

bool UNIT_TEST_Configuration::Configuration08()
{
    string name = "Configuration08";
    //! data ------------------------------------
    string filePath = "test/unit_test_Configuration/test_case/input/config8.txt";
    int NUM_ROWS = 0;
    int NUM_COLS = 0;
    vector<UNIT_NAME> units;
    int EVENT_CODE = 0;
    TerrainType **battlefield;

    //! process ---------------------------------
    processFile(filePath, battlefield, NUM_ROWS, NUM_COLS, units, EVENT_CODE);
    string result;
    result += "NUM_ROWS: " + to_string(NUM_ROWS) + "\n";
    result += "NUM_COLS: " + to_string(NUM_COLS) + "\n";
    result += print_battlefield((const TerrainType**)battlefield, NUM_ROWS, NUM_COLS) + "\n";
    result += print_UNIT_NAME(units) + "\n";
    result += "EVENT_CODE: ";
    result += to_string(EVENT_CODE) + "\n";

    clearBattlefield(battlefield, NUM_ROWS, NUM_COLS);

    //! expect ----------------------------------
    string expect = 
R"expect(NUM_ROWS: 3
NUM_COLS: 3
RIV ROA ROA
FOR ROA ROA
ROA RIV URB
[
ENGINEER(3,2,(1,1),0),
SNIPER(5,1,(0,2),1)
]
EVENT_CODE: 11
)expect";

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! remove data -----------------------------

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}