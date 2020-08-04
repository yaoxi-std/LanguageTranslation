#include "Analyzer.h"
#include "word_analyze/WordAnalyzer.h"
#include <fstream>
#include <vector>
#include <string>
#include <ios>
#include <iostream>
using std::fstream;
using std::vector;
using std::string;
using std::ios;
using std::cout;
using std::endl;

int main(int argc, char** argv){
    language_translation::WordAnalyzer* wd = language_translation::Analyzer::getWordAnalyzer("c++");
    fstream fs("test/a.txt", ios::in);
    string strin = "", line = "";
    while(getline(fs, line)){
        strin += line + "\n";
    }
    cout<<strin<<endl;
    vector<string> res = wd->analyze(strin);
    for(auto s : res) cout<<s<<endl;
    return 0;
}