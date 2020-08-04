#ifndef _WORDANALYZER_H
#define _WORDANALYZER_H

#include <string>
#include <vector>
using std::string;
using std::vector;

namespace language_translation{

class WordAnalyzer{
public:
    bool isAWord(char ch);
    virtual vector<string> analyze(string strin);
};

}

#endif