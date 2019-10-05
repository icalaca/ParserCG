#include <string>
#include <vector>

using namespace std;

class Parser
{
private:
    vector<vector<int>> colors;
    vector<vector<vector<int>>> objects;
    vector<int> splitCast(const string& s, const char d);

public:
    Parser(const char *config);
    int getColorR(int colorid);
    int getColorG(int colorid);
    int getColorB(int colorid);
    int getNumColors();
    int getObjElement(int objid, int line, int column);
    int getObjNumLines(int objid);
    int getObjNumColumns(int objid);
    int getNumObjs();
};
