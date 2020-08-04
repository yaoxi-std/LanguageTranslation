#include "Analyzer.h"

language::translation::WordAnalyzer*
language::translation::Analyzer::getWordAnalyzer(string lang){
    if(lang == "c++"){
        return new language::translation::CppWordAnalyzer();
    }
    /* Return more languages here */
    return nullptr;
}
language::translation::GrammarAnalyzer*
language::translation::Analyzer::getGrammarAnalyzer(string lang){
    /* Return more languages here */
    return nullptr;
}