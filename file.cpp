#include "file.h"

File::File(string file):m_file(file)
{
    
}

vector<char *> File::read_file()
{
    ifstream infile(m_file);
    vector<char*> result;
    string line;
    while(getline(infile,line))
    {
        result.push_back(line.c_str());
    }
    
    return result;    
}
