#include "WordAnalyzer.h"

bool
language_translation::WordAnalyzer::isAWord(char ch){
    return (ch>='a'&&ch<='z') || (ch>='A'&&ch<='Z') || (ch>='0'&&ch<='9') || (ch=='_');
}

vector<string>
language_translation::WordAnalyzer::analyze(string strin){
    vector<string> res; res.clear();
    /* Analyze here */
    int is_a_word = isAWord(strin[0]);
    string word = "";
    for(int i=0; i<strin.size(); i++){
        if(strin[i] == '\"'){
            if(word != "" && word != "/") res.push_back(word); word = "";
            int pos = i + 1;
            while(strin[pos] != '\"') pos++;
            res.push_back(strin.substr(i, pos-i+1));
            i = pos;
        }else if(strin[i] == '\n'){
            if(word != "" && word != "/") res.push_back(word); word = "";
            res.push_back("\n");
        }else if(i > 0 && strin[i] == '/' && strin[i-1] == '/'){ // "<code> // <remind>"
            if(word != "" && word != "/") res.push_back(word); word = "";
            int pos = i + 1;
            while(pos < strin.size() && strin[pos] != '\n') pos++;
            res.push_back(strin.substr(i-1, pos-i+1));
            i = pos;
        }else if(strin[i] == ' ' || strin[i] == '\t'){ // "<code> <code>"
            if(word != "") res.push_back(word); word = "";
            is_a_word = 3;
        }else if( // "<code> { <code> }"
            strin[i] == '{' || strin[i] == '}' || 
            strin[i] == '[' || strin[i] == ']' || 
            strin[i] == '(' || strin[i] == ')'
        ){
            if(word != "") res.push_back(word); word = "";
            word += strin[i];
            res.push_back(word);
            word = "";
            is_a_word = 3;
        }else if(isAWord(strin[i]) != is_a_word){
            if(word != "") res.push_back(word); word = "";
            word += strin[i];
            is_a_word = isAWord(strin[i]);
        }else{
            word += strin[i];
        }
    }
    if(word != "") res.push_back(word); word = "";
    return res;
}