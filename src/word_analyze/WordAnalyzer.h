#ifndef _WORDANALYZER_H
#define _WORDANALYZER_H

#include <fstream>
using std::fstream;

namespace language::translation{

class WordAnalyzer{
public:
    virtual bool analyze(fstream streamin, fstream &streamout);
};

}

#endif