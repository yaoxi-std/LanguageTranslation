#include "Analyzer.h"

language_translation::WordAnalyzer*
language_translation::Analyzer::getWordAnalyzer(string lang){
    /* Return more languages here */
    return new WordAnalyzer();
}
language_translation::GrammarAnalyzer*
language_translation::Analyzer::getGrammarAnalyzer(string lang){
    /* Return more languages here */
    return new GrammarAnalyzer();
}