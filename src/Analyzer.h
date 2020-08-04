#ifndef _ANALYZER_H
#define _ANALYZER_H

#include "grammar_analyze/GrammarAnalyzer.h"
#include "word_analyze/WordAnalyzer.h"
#include <string>
using std::string;

namespace language_translation{

class Analyzer{
public:
    static WordAnalyzer* getWordAnalyzer(string lang);
    static GrammarAnalyzer* getGrammarAnalyzer(string lang);
};

}

#endif