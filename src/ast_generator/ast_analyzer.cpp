#ifndef _AST_ANALYZER_CPP
#define _AST_ANALYZER_CPP

#include "Infos.h"

namespace ast{

static vector<string> types;

static bool is_a_type(string type){
    for(int i=0; i<types.size(); i++) if(types[i] == type) return true;
    return false;
}

static bool add_type(string type){
    if(is_a_type(type)) return false;
    return true;
}

static void init_type(){
    types = vector<string>{
        "int",
        "void",
        "double",
        "float",
        "long",
        "unsigned",
        "char"
    };
}

ast_node* analyze(vector<string> words){
    init_type();
    file_info finfo;
    finfo.elements.clear();
    for(int i=0; i<words.size(); i++){
        if(words[i] == "#"){
            // defines or includes
            if(words[i+1] == "include"){
                finfo.elements.push_back(new include_info(words[i+3]));
                i += 4;
            }
            ////////
        }else if(words[i] == "using"){
            if(words[i+1] == "namespace"){
                finfo.elements.push_back(new namespace_info(words[i+2]));
            }else{
                // using <namespace>::<infos>
                // using <varname> = <varinfo>
            }
        }else if(is_a_type(words[i])){
            string type_name = words[i+1];
            if(words[i+2] == "("){
                // function
                int pos = i+3;
                while(words[pos] != ")") pos++;
                vector<variable_info*> inp; inp.clear();
                string typ, nam;
                for(int j=i+3; j<=pos; j++){
                    if((j-i) % 3 == 0) typ = words[j];
                    else if((j-i) % 3 == 1) nam = words[j];
                    else inp.push_back(new variable_info(typ, nam));
                }
                finfo.elements.push_back(new function_info(
                    new variable_list_info(inp),
                    new type_info(words[i]),
                    new field_info(),
                    words[i+1]
                ));
            }else{
                // variable
                
            }
        }else{

        }
    }
}

}

#endif