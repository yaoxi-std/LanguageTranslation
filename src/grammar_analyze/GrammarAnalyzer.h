#ifndef _GRAMMARANALYZER_H
#define _GRAMMARANALYZER_H

#include <fstream>
using std::fstream;

namespace language::translation{

class GrammarAnalyzer{
public:
    virtual bool analyze(fstream streamin, fstream &streamout);
};

}

#endif