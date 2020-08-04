#ifndef _CPPWORDANALYZER_H
#define _CPPWORDANALYZER_H

#include "../WordAnalyzer.h"
#include <ios>
using std::ios;

namespace language::translation{

class CppWordAnalyzer : public WordAnalyzer{
public:
    bool analyze(fstream streamin, fstream &streamout);
};

}

#endif