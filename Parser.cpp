#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Parser.hpp"

using namespace std;

vector<int> Parser::splitCast(const string &s, const char d)
{
    vector<int> tokens;
    string token;
    for (int i = 0; i < s.size() + 1; i++)
    {
        if (i == s.size() || s.at(i) == d)
        {
            if (token.size())
                tokens.push_back(stoi(token));
            token.clear();
        }
        else token += s.at(i);
    }
    return tokens;
}

Parser::Parser(const char *config)
{
    string l;
    int ncolors = 0;
    int objlines = 0;
    int objcolumns = 0;
    ifstream f(config);
    if (f.is_open())
    {
        while (getline(f, l))
        {
            if (!l.compare("#CORES") and getline(f, l))
            {
                ncolors = stoi(l);
                while (ncolors && getline(f, l))
                {
                    vector<int> v = splitCast(l, ' ');
                    vector<int> color{v[1], v[2], v[3]};
                    colors.push_back(color);
                    ncolors--;
                }
            }
            if (!l.compare("#OBJETO") and getline(f, l))
            {
                vector<int> v = splitCast(l, ' ');
                objlines = v[0];
                objcolumns = v[1];
                vector<vector<int>> line;
                while (objlines && getline(f, l))
                {
                    vector<int> v = splitCast(l, ' ');
                    line.push_back(v);
                    objlines--;
                }
                objects.push_back(line);
            }
        }
        f.close();
    }
    else cout << "ERROR";
}
int Parser::getColorR(int colorid)
{
    return colors[colorid - 1][0];
}
int Parser::getColorG(int colorid)
{
    return colors[colorid - 1][1];
}
int Parser::getColorB(int colorid)
{
    return colors[colorid - 1][2];
}
int Parser::getNumColors()
{
    return colors.size();
}
int Parser::getObjElement(int objid, int line, int column)
{
    return objects[objid][line][column];
}
int Parser::getObjNumLines(int objid)
{
    return objects[objid].size();
}
int Parser::getObjNumColumns(int objid)
{
    return objects[objid][0].size();
}
int Parser::getNumObjs()
{
    return objects.size();
}