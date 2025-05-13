#include "Configuration.h"

// * Hint: Bạn có thể thêm hoặc thay thế các phương thức khác để truy cập các thành viên riêng tư nếu cần thiết.
string trim(const string &s) 
{
    size_t start = s.find_first_not_of(" \t\r\n");
    size_t end = s.find_last_not_of(" \t\r\n");
    return (start == string::npos) ? "" : s.substr(start, end - start + 1);
}

vector<string> split(const string& s, char delimiter) 
{
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(trim(token));
    }
    return tokens;
}

//!-----------------------------------------------------
//! CLASS Configuration
//!-----------------------------------------------------
Configuration::Configuration(const std::string &filepath) {
    ifstream fin(filepath);
    string line;
    while (getline(fin, line)) {
        line = trim(line);
        if (line.empty() || line[0] == '#') continue;
        if (line.find("NUM_ROWS=") == 0) {
            num_rows = stoi(line.substr(9));
        } else if (line.find("NUM_COLS=") == 0) {
            num_cols = stoi(line.substr(9));
        } else if (line.find("ARRAY_FOREST=") == 0) {
            string arr = line.substr(13);
            arr = arr.substr(1, arr.size() - 2); // remove []
            for (auto& posStr : split(arr, ',')) {
                if (!posStr.empty())
                    arrayForest.push_back(new Position(trim(posStr)));
            }
        } else if (line.find("ARRAY_RIVER=") == 0) {
            string arr = line.substr(12);
            arr = arr.substr(1, arr.size() - 2);
            for (auto& posStr : split(arr, ',')) {
                if (!posStr.empty())
                    arrayRiver.push_back(new Position(trim(posStr)));
            }
        } else if (line.find("ARRAY_FORTIFICATION=") == 0) {
            string arr = line.substr(21);
            arr = arr.substr(1, arr.size() - 2);
            for (auto& posStr : split(arr, ',')) {
                if (!posStr.empty())
                    arrayFortification.push_back(new Position(trim(posStr)));
            }
        } else if (line.find("ARRAY_URBAN=") == 0) {
            string arr = line.substr(12);
            arr = arr.substr(1, arr.size() - 2);
            for (auto& posStr : split(arr, ',')) {
                if (!posStr.empty())
                    arrayUrban.push_back(new Position(trim(posStr)));
            }
        } else if (line.find("ARRAY_SPECIAL_ZONE=") == 0) {
            string arr = line.substr(19);
            arr = arr.substr(1, arr.size() - 2);
            for (auto& posStr : split(arr, ',')) {
                if (!posStr.empty())
                    arraySpecialZone.push_back(new Position(trim(posStr)));
            }
        } else if (line.find("UNIT_LIST=") == 0) {
            string arr = line.substr(10);
            arr = arr.substr(1, arr.size() - 2); // remove []
            vector<string> units;
            string tmp;
            int paren = 0;
            for (char ch : arr) {
                if (ch == '(') paren++;
                if (ch == ')') paren--;
                tmp += ch;
                if (paren == 0 && !tmp.empty() && tmp.find(')') != string::npos) {
                    units.push_back(trim(tmp));
                    tmp.clear();
                }
            }
            for (auto& u : units) {
                if (u.empty()) continue;
                size_t l = u.find('(');
                string type = trim(u.substr(0, l));
                string params = u.substr(l + 1, u.size() - l - 2); // remove ')'
                vector<string> vals = split(params, ',');
                int quantity = stoi(vals[0]);
                int weight = stoi(vals[1]);
                Position pos(vals[2]);
                int armyBelong = stoi(vals[3]);
                Unit* unit = nullptr;
                if (type == "TANK") {
                    unit = new Vehicle(quantity, weight, pos, TANK);
                } else if (type == "REGULARINFANTRY") {
                    unit = new Infantry(quantity, weight, pos, REGULARINFANTRY);
                }
                // Có thể bổ sung các loại khác nếu cần
                if (unit) {
                    if (armyBelong == 0) liberationUnits.push_back(unit);
                    else ARVNUnits.push_back(unit);
                }
            }
        } else if (line.find("EVENT_CODE=") == 0) {
            eventCode = stoi(line.substr(11));
        }
    }
    fin.close();
}

Configuration::~Configuration() 
{
    for (auto p : arrayForest) delete p;
    for (auto p : arrayRiver) delete p;
    for (auto p : arrayFortification) delete p;
    for (auto p : arrayUrban) delete p;
    for (auto p : arraySpecialZone) delete p;
    for (auto u : liberationUnits) delete u;
    for (auto u : ARVNUnits) delete u;
}

string Configuration::str() const 
{
ostringstream oss;
    oss << "num_rows=" << num_rows << ",";
    oss << "num_cols=" << num_cols << ",";
    auto printArr = [&](const string& name, const vector<Position*>& arr) 
    {
        oss << name << "=[";
        for (size_t i = 0; i < arr.size(); ++i) {
            oss << arr[i]->str();
            if (i + 1 < arr.size()) oss << ",";
        }
        oss << "],";
    };
    printArr("arrayForest", arrayForest);
    printArr("arrayRiver", arrayRiver);
    printArr("arrayFortification", arrayFortification);
    printArr("arrayUrban", arrayUrban);
    printArr("arraySpecialZone", arraySpecialZone);

    oss << "liberationUnits=[";
    for (size_t i = 0; i < liberationUnits.size(); ++i) {
        oss << liberationUnits[i]->str();
        if (i + 1 < liberationUnits.size()) oss << ",";
    }
    oss << "],";

    oss << "ARVNUnits=[";
    for (size_t i = 0; i < ARVNUnits.size(); ++i) {
        oss << ARVNUnits[i]->str();
        if (i + 1 < ARVNUnits.size()) oss << ",";
    }
    oss << "],";
    oss << "eventCode=" << eventCode;
    return oss.str();   
}