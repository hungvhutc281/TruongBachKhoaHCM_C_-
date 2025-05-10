#include "Configuration.h"
TerrainType coor(string m){
    if(m=="ROAD") return ROAD;
    if(m=="FOREST") return FOREST;
    if(m=="RIVER") return RIVER;
    if(m=="FORTIFICATION") return FORTIFICATION;
    if(m=="URBAN") return URBAN;
    if(m=="SPECIAL_ZONE") return SPECIAL_ZONE;
    return ROAD;
}
string trim(const string &m){
    size_t start = m.find_first_not_of(" \t\r\n");
    size_t end = m.find_last_not_of(" \t\r\n");
    return (start == string::npos?"":m.substr(start,end-start+1));
}
InfantryType Re_name(string s){
    if(s=="SNIPER") return SNIPER;
    else if(s=="ANTIAIRCRAFTSQUAD") return ANTIAIRCRAFTSQUAD;
    else if(s=="MORTARSQUAD") return MORTARSQUAD;
    else if(s=="ENGINEER") return ENGINEER;
    else if(s=="SPECIALFORCES") return SPECIALFORCES;
    else return REGULARINFANTRY;
}
void processFile(const string &filename, TerrainType **&battlefield, int &NUM_ROWS, int &NUM_COLS, vector<UNIT_NAME> &units, int &EVENT_CODE)
{
ifstream fs;
    fs.open(filename);
    string s;
    vector<string> v;
    while(getline(fs,s)){
        v.push_back(s);
    }
    fs.close();
    
    for(string x:v){
        size_t pos;
    if ((pos = x.find("NUM_ROWS")) != string::npos) {
        NUM_ROWS = stoi(trim(x.substr(x.find('=') + 1)));
    }
    if ((pos = x.find("NUM_COLS")) != string::npos) {
        NUM_COLS = stoi(trim(x.substr(x.find('=') + 1)));
    }
    if ((pos = x.find("EVENT_CODE")) != string::npos) {
        int start = x.find("=");
        if(x.size()-1-start>2){
            EVENT_CODE = stoi(trim(x.substr(x.size()-2)));
        }
        else EVENT_CODE = stoi(trim(x.substr(start+1)));
        
    } 
    }
    battlefield =new TerrainType*[NUM_ROWS];
    for(int i = 0; i < NUM_ROWS; i++){
        battlefield[i] = new TerrainType[NUM_COLS];
        for (int j = 0 ; j < NUM_COLS; j++){
            battlefield[i][j] = ROAD;
        }
    }
    for (string x: v){
        stringstream ss;
        if(x.find("ARRAY_") != string::npos){
            int a = x.find('[');
            int b = x.rfind(']');
            int c = x.find('_');
            int d = x.find('=');
            string name = x.substr(c+1,d-c-1);
            string s;
            if(a+1!=b){
            ss << x.substr(a+1,b-a-1);
            while(getline(ss,s,')')){
                size_t star =s.find('(');
                string pair = s.substr(star+1);
                size_t mid = pair.find(',');
                string x_str = pair.substr(0,mid);
                string y_str = pair.substr(mid+1);
                int x = stoi(x_str);
                int y = stoi(y_str);
                TerrainType z = coor(name);
                battlefield[x][y] = z;
            }}

            }
        }
        

        for(string m : v){
            m = trim(m);
            if(m.find("SNIPER")!=string::npos||m.find("ANTIAIRCRAFTSQUAD")!=string::npos||m.find("MORTARSQUAD")!=string::npos||m.find("ENGINEER")!=string::npos||m.find("SPECIALFORCES")!=string::npos
            ||m.find("REGULARINFANTRY")!=string::npos){
                int start = m.find('(');
                int end = m.rfind(')');
                string a = m.substr(0,start);
                string token = m.substr(start+1,end-start-1);
                string clean ="";
                for(char x: token){
                    if(x!='(' && x!=')'){
                        clean += x;
                    }
                }
                stringstream ss(clean) ;
                string child;
                vector<int> number;
                while(getline(ss,child,',')){
                    number.push_back(stoi(trim(child)));
                }
                InfantryType z =Re_name(a);
                UNIT_NAME s;
                s.type = z;
                s.quantity = number[0];
                s.weight = number[1];
                s.position_x = number[2];
                s.position_y=number[3];
                if(number[4]==1) s.armyBelong=true;
                else s.armyBelong = false;

                units.push_back(s);
            }
        }
    }
string print_battlefield(const TerrainType **battlefield, const int &NUM_ROWS, const int &NUM_COLS)
{
 ostringstream ss;
        for (int i = 0; i < NUM_ROWS; i++) 
        {
            for (int j = 0; j < NUM_COLS; j++) 
            {
                if (battlefield[i][j] == ROAD)
                 {
                    ss << "ROA";
                } else if (battlefield[i][j] == FOREST)
                 {
                    ss << "FOR";
                } else if (battlefield[i][j] == RIVER) 
                {
                    ss << "RIV";
                } else if (battlefield[i][j] == FORTIFICATION) 
                {
                    ss << "FOR";
                } else if (battlefield[i][j] == URBAN) 
                {
                    ss << "URB";
                } else if (battlefield[i][j] == SPECIAL_ZONE)
                {
                    ss << "SPE";
                }
                if (j != NUM_COLS - 1) 
                {
                    ss << " ";
                }
            }
            if (i != NUM_ROWS - 1) {
                ss << "\n";
            }
        }
        return ss.str();
    }
string print_UNIT_NAME(const vector<UNIT_NAME> &units) 
{
    ostringstream ss;
    ss << "[\n";
    for (int i = 0; i < units.size(); i++)
     {
        if (units[i].type == SNIPER) ss << "SNIPER(";
        else if (units[i].type == ANTIAIRCRAFTSQUAD) ss << "ANTIAIRCRAFTSQUAD(";
        else if (units[i].type == MORTARSQUAD) ss << "MORTARSQUAD(";
        else if (units[i].type == ENGINEER) ss << "ENGINEER(";
        else if (units[i].type == SPECIALFORCES) ss << "SPECIALFORCES(";
        else ss << "REGULARINFANTRY(";
 ss << units[i].quantity<< ","<< units[i].weight<< ",("<< units[i].position_x << "," << units[i].position_y << "),"<< units[i].armyBelong << ")";
    
        if (i < units.size() - 1) 
        {
            ss << ",\n";
        }
    }
    ss << "\n]";
    return ss.str();
}
void clearBattlefield(TerrainType **battlefield, const int &NUM_ROWS, const int &NUM_COLS)
{
    // TODO
battlefield=new TerrainType*[NUM_ROWS];
for (int i=0;i<NUM_ROWS;i++)
{
    *(battlefield+i)=new TerrainType[NUM_COLS];
    for (int j=0;j<NUM_COLS;j++)
    {
        battlefield[i][j]=ROAD;
    }
}
}

  