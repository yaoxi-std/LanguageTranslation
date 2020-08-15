#ifndef _INFOS_H
#define _INFOS_H

#include <vector>
#include <string>
using namespace std;

struct ast_node{
};

struct include_info : ast_node{
    string includedfile;
    include_info(string inc){
        includedfile = inc;
    }
};

struct variable_info : ast_node{
    string vartype;
    string varname;
    variable_info(string typ, string nam){
        vartype = typ;
        varname = nam;
    }
};

struct operator_type_info : ast_node{
    string operatorname;
};

struct once_operator_info : ast_node{
    ast_node *var;
    operator_type_info *oper;
};

struct twice_operator_info : ast_node{
    ast_node *lvar, *rvar;
    operator_type_info *oper;
};

struct three_times_operator_info : ast_node{
    ast_node *lvar, *mvar, *rvar;
    operator_type_info *oper;
};

struct field_info : ast_node{
    vector<ast_node*> sentences;
};

struct variable_list_info : ast_node{
    vector<variable_info*> vars;
    variable_list_info(vector<variable_info*> v){
        vars = v;
    }
};

struct type_info : ast_node{
    string typname;
    type_info(string nam){
        typname = nam;
    }
};

struct function_info : ast_node{
    variable_list_info* inputvars;
    type_info* outputvar;
    field_info* implementation;
    string name;
    function_info(variable_list_info* inp, type_info* out, field_info* impl, string nam){
        inputvars = inp;
        outputvar = out;
        implementation = impl;
        name = nam;
    }
};

struct structure_info : ast_node{
    string strcname;
    vector<variable_info*> vars;
    vector<function_info*> funcs;
};

struct class_function_info : function_info{
    int flag; // public or private or protected
};

struct class_variable_info : variable_info{
    int flag; // public or private or protected
};

struct class_info : structure_info{
    string clsname;
    vector<class_variable_info*> vars;
    vector<class_function_info*> funcs;
};

struct file_info : ast_node{
    vector<ast_node*> elements;
};

struct namespace_info : ast_node{
    string name;
    vector<ast_node*> elements;
    namespace_info(string nam){
        name = nam;
        elements.clear();
    }
};

#endif