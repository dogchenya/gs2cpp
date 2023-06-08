%{
#include <iostream>
#include <memory>
#include <cassert>

using namespace std;

#define YYSTYPE GrammarBasePtr

#include "parse.h"
#define YYDEBUG 1
#define YYINITDEPTH 10000
%}

%defines
%debug

//keyword token
%token GAUSSIAN_VOID
%token GAUSSIAN_STRUCT
%token GAUSSIAN_ROS_PARAMS
%token GAUSSIAN_BOOL
%token GAUSSIAN_BYTE
%token GAUSSIAN_SHORT
%token GAUSSIAN_INT
%token GAUSSIAN_DOUBLE
%token GAUSSIAN_FLOAT
%token GAUSSIAN_LONG
%token GAUSSIAN_STRING
%token GAUSSIAN_VECTOR
%token GAUSSIAN_MAP
%token GAUSSIAN_NAMESPACE
%token GAUSSIAN_ROS_NAMESPACE
%token GAUSSIAN_PARAM_CALLBACK
%token GAUSSIAN_INTERFACE
%token GAUSSIAN_IDENTIFIER
%token GAUSSIAN_OUT
%token GAUSSIAN_OP
%token GAUSSIAN_KEY
%token GAUSSIAN_ROUTE_KEY
%token GAUSSIAN_REQUIRE
%token GAUSSIAN_OPTIONAL
%token GAUSSIAN_CONST_INTEGER
%token GAUSSIAN_CONST_FLOAT
%token GAUSSIAN_FALSE
%token GAUSSIAN_TRUE
%token GAUSSIAN_STRING_LITERAL
%token GAUSSIAN_SCOPE_DELIMITER
%token GAUSSIAN_CONST
%token GAUSSIAN_ENUM
%token GAUSSIAN_UNSIGNED
%token BAD_CHAR

%%
start: definitions
;

// ----------------------------------------------------------------------
definitions
// ----------------------------------------------------------------------
: definition
{
}
';' definitions
| error ';'
{
    yyerrok;
}
definitions
| definition
{
    g_parse->error("`;' missing after definition");
}
|
{
}
;

// ----------------------------------------------------------------------
definition
// ----------------------------------------------------------------------
: namespace_def
{
    assert($1 == 0 || std::dynamic_pointer_cast<Namespace>($1));
}
| interface_def
{
    assert($1 == 0 || std::dynamic_pointer_cast<Interface>($1));
}
| ros_params_def
{
    assert($1 == 0 || std::dynamic_pointer_cast<RosParams>($1));
}
| struct_def
{
    assert($1 == 0 || std::dynamic_pointer_cast<Struct>($1));
}
| key_def
{
}
| enum_def
{
    assert($1 == 0 || std::dynamic_pointer_cast<Enum>($1));
}
| const_def
{
    assert($1 == 0 || std::dynamic_pointer_cast<Const>($1));
}
;

// ----------------------------------------------------------------------
enum_def
// ----------------------------------------------------------------------
: enum_id
{
    $$ = $1;
}
'{' enumerator_list '}'
{
    if($3)
    {
        g_parse->popContainer();
        $$ = $3;
    }
    else
    {
        $$ = 0;
    }

    $$ = $2;
}
;

// ----------------------------------------------------------------------
enum_id
// ----------------------------------------------------------------------
: GAUSSIAN_ENUM GAUSSIAN_IDENTIFIER
{
    NamespacePtr c = std::dynamic_pointer_cast<Namespace>(g_parse->currentContainer());
    if(!c)
    {
        g_parse->error("enum must define in namespace");
    }
    StringGrammarPtr ident  = std::dynamic_pointer_cast<StringGrammar>($2);
    EnumPtr e = c->createEnum(ident->v);
    g_parse->pushContainer(e);

    $$ = e;
}
| GAUSSIAN_ENUM keyword
{
    StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>($2);
    g_parse->error("keyword `" + ident->v + "' cannot be used as enumeration name");
    $$ = $2;
}
;

// ----------------------------------------------------------------------
enumerator_list
// ----------------------------------------------------------------------
: enumerator ',' enumerator_list
{
    $$ = $2;
}
| enumerator
{
}
;

// ----------------------------------------------------------------------
enumerator
// ----------------------------------------------------------------------
: GAUSSIAN_IDENTIFIER
{
    TypePtr type        = std::dynamic_pointer_cast<Type>(g_parse->createBuiltin(Builtin::KindLong));
    StringGrammarPtr ident  = std::dynamic_pointer_cast<StringGrammar>($1);
    TypeIdPtr tPtr      = std::make_shared<TypeId>(type, ident->v);
    tPtr->disableDefault();
    EnumPtr e = std::dynamic_pointer_cast<Enum>(g_parse->currentContainer());
    assert(e);
    e->addMember(tPtr);
    $$ = e;
}
| keyword
{
    StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>($1);
    g_parse->error("keyword `" + ident->v + "' cannot be used as enumerator");
}
| GAUSSIAN_IDENTIFIER  '=' const_initializer 
{
    TypePtr type        = std::dynamic_pointer_cast<Type>(g_parse->createBuiltin(Builtin::KindLong));
    StringGrammarPtr ident  = std::dynamic_pointer_cast<StringGrammar>($1);
    TypeIdPtr tPtr      = std::make_shared<TypeId>(type, ident->v);
    ConstGrammarPtr sPtr    = std::dynamic_pointer_cast<ConstGrammar>($3);
    g_parse->checkConstValue(tPtr, sPtr->t);
    tPtr->setDefault(sPtr->v);
    EnumPtr e = std::dynamic_pointer_cast<Enum>(g_parse->currentContainer());
    assert(e);
    e->addMember(tPtr);
    $$ = e;
}
| 
{
}
;

// ----------------------------------------------------------------------
namespace_def
// ----------------------------------------------------------------------
: GAUSSIAN_NAMESPACE GAUSSIAN_IDENTIFIER
{
    StringGrammarPtr ident  = std::dynamic_pointer_cast<StringGrammar>($2);
    ContainerPtr c      = g_parse->currentContainer();
    NamespacePtr n      = c->createNamespace(ident->v);
    if(n)
    {
        g_parse->pushContainer(n);
        $$ = std::dynamic_pointer_cast<GrammarBase>(n);
    }
    else
    {
        $$ = 0;
    }
}
'{' definitions '}'
{
    if($3)
    {
        g_parse->popContainer();
        $$ = $3;
    }
    else
    {
        $$ = 0;
    }
}
;


//key------------------------------------------------------
key_def
// ----------------------------------------------------------------------
: GAUSSIAN_KEY '[' scoped_name ','
{
    StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>($3);
    StructPtr sp = std::dynamic_pointer_cast<Struct>(g_parse->findUserType(ident->v));
    if(!sp)
    {
        g_parse->error("struct '" + ident->v + "' undefined!");
    }

    g_parse->setKeyStruct(sp);
}
key_members ']'
{
}
;

//key------------------------------------------------------
key_members
// ----------------------------------------------------------------------
: GAUSSIAN_IDENTIFIER
{
    StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>($1);
    StructPtr np = g_parse->getKeyStruct();
    if(np)
    {
        np->addKey(ident->v);
    }
    else
    {
        $$ = 0;
    }
}
| key_members ',' GAUSSIAN_IDENTIFIER
{
    StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>($3);
    StructPtr np = g_parse->getKeyStruct();
    if(np)
    {
        np->addKey(ident->v);
    }
    else
    {
        $$ = 0;
    }   
}
;

// ----------------------------------------------------------------------
interface_def
// ----------------------------------------------------------------------
: interface_id
{
    StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>($1);

    NamespacePtr c = std::dynamic_pointer_cast<Namespace>(g_parse->currentContainer());

    InterfacePtr cl = c->createInterface(ident->v);
    if(cl)
    {
        g_parse->pushContainer(cl);
        $$ = std::dynamic_pointer_cast<GrammarBase>(cl);
    }
    else
    {
        $$ = 0;
    }
}
'{' interface_exports '}'
{
    if($2)
    {
       g_parse->popContainer();
       $$ = std::dynamic_pointer_cast<GrammarBase>($2);
    }
    else
    {
       $$ = 0;
    }
}
;

// ----------------------------------------------------------------------
interface_id
// ----------------------------------------------------------------------
: GAUSSIAN_INTERFACE GAUSSIAN_IDENTIFIER
{
    $$ = $2;
}
| GAUSSIAN_INTERFACE keyword
{
    StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>($2);
    g_parse->error("keyword `" + ident->v + "' cannot be used as interface name");
    $$ = $2;
}
;

// ----------------------------------------------------------------------
interface_exports
// ----------------------------------------------------------------------
: interface_export ';' interface_exports
{
}
| error ';' interface_exports
{
}
| interface_export
{
    g_parse->error("`;' missing after definition");
}
|
{
}
;

// ----------------------------------------------------------------------
interface_export
// ----------------------------------------------------------------------
: operation
;

// ----------------------------------------------------------------------
operation
// ----------------------------------------------------------------------
: operation_preamble parameters ')'
{
    if($1)
    {
        g_parse->popContainer();
        $$ = std::dynamic_pointer_cast<GrammarBase>($1);
    }
    else
    {
        $$ = 0;
    }
}
;

// ----------------------------------------------------------------------
operation_preamble
// ----------------------------------------------------------------------
: return_type GAUSSIAN_OP
{
    TypePtr returnType = std::dynamic_pointer_cast<Type>($1);
    StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>($2);
    string name        = ident->v;
    InterfacePtr cl    = std::dynamic_pointer_cast<Interface>(g_parse->currentContainer());
    if(cl)
    {
         OperationPtr op = cl->createOperation(name, returnType);
         if(op)
         {
             g_parse->pushContainer(op);
             $$ = std::dynamic_pointer_cast<GrammarBase>(op);
         }
         else
         {
             $$ = 0;
         }
    }
    else
    {
        $$ = 0;
    }
}
;

// ----------------------------------------------------------------------
return_type
// ----------------------------------------------------------------------
: type
| GAUSSIAN_VOID
{
    $$ = 0;
}
;


// ----------------------------------------------------------------------
parameters
// ----------------------------------------------------------------------
: // empty
{
}
| type_id
{
    TypeIdPtr  tsp         = std::dynamic_pointer_cast<TypeId>($1);

    OperationPtr op = std::dynamic_pointer_cast<Operation>(g_parse->currentContainer());
    assert(op);
    if(op)
    {
        op->createParamDecl(tsp, false, false);
    }
}
| parameters ',' type_id
{
    TypeIdPtr  tsp         = std::dynamic_pointer_cast<TypeId>($3);

    OperationPtr op = std::dynamic_pointer_cast<Operation>(g_parse->currentContainer());
    assert(op);
    if(op)
    {
        op->createParamDecl(tsp, false, false);
    }
}
| out_qualifier type_id
{
    BoolGrammarPtr isOutParam  = std::dynamic_pointer_cast<BoolGrammar>($1);
    TypeIdPtr  tsp         = std::dynamic_pointer_cast<TypeId>($2);

    OperationPtr op = std::dynamic_pointer_cast<Operation>(g_parse->currentContainer());
    assert(op);
    if(op)
    {
        op->createParamDecl(tsp, isOutParam->v, false);
    }
}
| parameters ',' out_qualifier type_id
{
    BoolGrammarPtr isOutParam  = std::dynamic_pointer_cast<BoolGrammar>($3);
    TypeIdPtr  tsp         = std::dynamic_pointer_cast<TypeId>($4);

    OperationPtr op = std::dynamic_pointer_cast<Operation>(g_parse->currentContainer());
    assert(op);
    if(op)
    {
        op->createParamDecl(tsp, isOutParam->v, false);
    }
}
| routekey_qualifier type_id
{
    BoolGrammarPtr isRouteKeyParam  = std::dynamic_pointer_cast<BoolGrammar>($1);
    TypeIdPtr  tsp              = std::dynamic_pointer_cast<TypeId>($2);

    OperationPtr op = std::dynamic_pointer_cast<Operation>(g_parse->currentContainer());
    assert(op);
    if(op)
    {
         op->createParamDecl(tsp, false, isRouteKeyParam->v);
    }
}
| parameters ',' routekey_qualifier type_id
{
    BoolGrammarPtr isRouteKeyParam = std::dynamic_pointer_cast<BoolGrammar>($3);
    TypeIdPtr  tsp             = std::dynamic_pointer_cast<TypeId>($4);

    OperationPtr op = std::dynamic_pointer_cast<Operation>(g_parse->currentContainer());
    assert(op);
    if(op)
    {
         op->createParamDecl(tsp, false, isRouteKeyParam->v);
    }
}
| out_qualifier 
{
    g_parse->error("'out' must be defined with a type");
}
| routekey_qualifier 
{
    g_parse->error("'routekey' must be defined with a type");
}
;

// ----------------------------------------------------------------------
routekey_qualifier
// ----------------------------------------------------------------------
: GAUSSIAN_ROUTE_KEY
{
    BoolGrammarPtr routekey = std::make_shared<BoolGrammar>();
    routekey->v = true;
    $$ = std::dynamic_pointer_cast<GrammarBase>(routekey);
}
;

// ----------------------------------------------------------------------
out_qualifier
// ----------------------------------------------------------------------
: GAUSSIAN_OUT
{
    BoolGrammarPtr out = std::make_shared<BoolGrammar>();
    out->v = true;
    $$ = std::dynamic_pointer_cast<GrammarBase>(out);
}
;

// ----------------------------------------------------------------------
ros_params_def
// ----------------------------------------------------------------------
: ros_params_id
{
    StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>($1);
    NamespacePtr np = std::dynamic_pointer_cast<Namespace>(g_parse->currentContainer());
    if(np)
    {
         RosParamsPtr sp = np->createRosParams(ident->v);
         if(sp)
         {
             g_parse->pushContainer(sp);
             $$ = std::dynamic_pointer_cast<GrammarBase>(sp);
         }
         else
         {
             $$ = 0;
         }
    }
    else
    {
       g_parse->error("ros_params '" + ident->v + "' must definition in namespace");
    }
}
'{' ros_params_exports '}'
{
    if($2)
    {
        g_parse->popContainer();
    }
    $$ = $2;

    RosParamsPtr st = std::dynamic_pointer_cast<RosParams>($$);
    assert(st);
    if(st->getAllMemberPtr().size() == 0)
    {
        g_parse->error("ros_params `" + st->getSid() + "' must have at least one member");
    }
}
;

// ros_params name----------------------------------------------------------
ros_params_id
// ----------------------------------------------------------------------
: GAUSSIAN_ROS_PARAMS GAUSSIAN_IDENTIFIER
{
    $$ = $2;
}
| GAUSSIAN_ROS_PARAMS keyword
{
    StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>($2);

    g_parse->error("keyword `" + ident->v + "' cannot be used as ros_params name");
}
| GAUSSIAN_ROS_PARAMS error
{
    g_parse->error("abstract declarator '<anonymous ros_params>' used as declaration");
}
;

// ros_params members------------------------------------------------------
ros_params_exports
// ----------------------------------------------------------------------
: ros_params_data_member ';' ros_params_exports
{

}
| ros_params_data_member
{
   g_parse->error("';' missing after definition");
}
|
{
}
;

// ros_params data member--------------------------------------------------------------
ros_params_data_member
// ----------------------------------------------------------------------
: ros_params_type_id
{
    $$ = std::dynamic_pointer_cast<GrammarBase>($1);
}
;

// ros_params member id--------------------------------------------------------------
ros_params_type_id
// ----------------------------------------------------------------------
: type_id '=' const_initializer GAUSSIAN_ROS_NAMESPACE
{
    RosParamsPtr np = std::dynamic_pointer_cast<RosParams>(g_parse->currentContainer());
    if(np)
    {
        TypeIdPtr tPtr   = std::dynamic_pointer_cast<TypeId>($1);
        ConstGrammarPtr sPtr = std::dynamic_pointer_cast<ConstGrammar>($3);
        g_parse->checkConstValue(tPtr, sPtr->t);
        StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>($4);
        tPtr->setNameSp(ident->v);
        tPtr->setDefault(sPtr->v);
        np->addTypeId(tPtr);
        $$ = std::dynamic_pointer_cast<GrammarBase>($1);
    }
    else
    {
        $$ = 0;
    }
}
| type_id const_initializer GAUSSIAN_IDENTIFIER
{
    RosParamsPtr np = std::dynamic_pointer_cast<RosParams>(g_parse->currentContainer());
    if(np)
    {
        TypeIdPtr tPtr   = std::dynamic_pointer_cast<TypeId>($1);
        ConstGrammarPtr sPtr = std::dynamic_pointer_cast<ConstGrammar>($2);
        g_parse->checkConstValue(tPtr, sPtr->t);
        StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>($3);
        tPtr->setNameSp(ident->v);
        tPtr->setDefault(sPtr->v);
        np->addTypeId(tPtr);
        $$ = std::dynamic_pointer_cast<GrammarBase>($1);
    }
    else
    {
        $$ = 0;
    }
}
| type_id const_initializer GAUSSIAN_IDENTIFIER GAUSSIAN_IDENTIFIER
{
    RosParamsPtr np = std::dynamic_pointer_cast<RosParams>(g_parse->currentContainer());
    if(np)
    {
        TypeIdPtr tPtr   = std::dynamic_pointer_cast<TypeId>($1);
        ConstGrammarPtr sPtr = std::dynamic_pointer_cast<ConstGrammar>($2);
        g_parse->checkConstValue(tPtr, sPtr->t);
        StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>($3);
        tPtr->setNameSp(ident->v);
        tPtr->setDefault(sPtr->v);
        StringGrammarPtr cb = std::dynamic_pointer_cast<StringGrammar>($4);
        tPtr->setCbName(cb->v);
        np->addTypeId(tPtr);
        $$ = std::dynamic_pointer_cast<GrammarBase>($1);
    }
    else
    {
        $$ = 0;
    }
}
|type_id const_initializer GAUSSIAN_ROS_NAMESPACE
{
    RosParamsPtr np = std::dynamic_pointer_cast<RosParams>(g_parse->currentContainer());
    if(np)
    {
        TypeIdPtr tPtr   = std::dynamic_pointer_cast<TypeId>($1);
        ConstGrammarPtr sPtr = std::dynamic_pointer_cast<ConstGrammar>($2);
        g_parse->checkConstValue(tPtr, sPtr->t);
        StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>($3);
        tPtr->setNameSp(ident->v);
        tPtr->setDefault(sPtr->v);
        np->addTypeId(tPtr);
        $$ = std::dynamic_pointer_cast<GrammarBase>($1);
    }
    else
    {
        $$ = 0;
    }
}
| type_id const_initializer GAUSSIAN_ROS_NAMESPACE GAUSSIAN_PARAM_CALLBACK
{
    RosParamsPtr np = std::dynamic_pointer_cast<RosParams>(g_parse->currentContainer());
    if(np)
    {
        TypeIdPtr tPtr   = std::dynamic_pointer_cast<TypeId>($1);
        ConstGrammarPtr sPtr = std::dynamic_pointer_cast<ConstGrammar>($2);
        g_parse->checkConstValue(tPtr, sPtr->t);
        StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>($3);
        tPtr->setNameSp(ident->v);
        tPtr->setDefault(sPtr->v);
        StringGrammarPtr cb = std::dynamic_pointer_cast<StringGrammar>($4);
        tPtr->setCbName(cb->v);
        np->addTypeId(tPtr);
        $$ = std::dynamic_pointer_cast<GrammarBase>($1);
    }
    else
    {
        $$ = 0;
    }
}
| type_id const_initializer GAUSSIAN_PARAM_CALLBACK
{
    RosParamsPtr np = std::dynamic_pointer_cast<RosParams>(g_parse->currentContainer());
    if(np)
    {
        TypeIdPtr tPtr   = std::dynamic_pointer_cast<TypeId>($1);
        ConstGrammarPtr sPtr = std::dynamic_pointer_cast<ConstGrammar>($2);
        g_parse->checkConstValue(tPtr, sPtr->t);
        tPtr->setDefault(sPtr->v);
        StringGrammarPtr cb = std::dynamic_pointer_cast<StringGrammar>($3);
        tPtr->setCbName(cb->v);
        np->addTypeId(tPtr);
        $$ = std::dynamic_pointer_cast<GrammarBase>($1);
    }
    else
    {
        $$ = 0;
    }
}
|type_id const_initializer
{
    RosParamsPtr np = std::dynamic_pointer_cast<RosParams>(g_parse->currentContainer());
    if(np)
    {
        TypeIdPtr tPtr   = std::dynamic_pointer_cast<TypeId>($1);
        ConstGrammarPtr sPtr = std::dynamic_pointer_cast<ConstGrammar>($2);
        g_parse->checkConstValue(tPtr, sPtr->t);
        tPtr->setDefault(sPtr->v);
        np->addTypeId(tPtr);
        $$ = std::dynamic_pointer_cast<GrammarBase>($1);
    }
    else
    {
        $$ = 0;
    }
}
| type_id '=' const_initializer
{
    RosParamsPtr np = std::dynamic_pointer_cast<RosParams>(g_parse->currentContainer());
    if(np)
    {
        TypeIdPtr tPtr   = std::dynamic_pointer_cast<TypeId>($1);
        ConstGrammarPtr sPtr = std::dynamic_pointer_cast<ConstGrammar>($3);
        g_parse->checkConstValue(tPtr, sPtr->t);
        tPtr->setDefault(sPtr->v);
        np->addTypeId(tPtr);
        $$ = std::dynamic_pointer_cast<GrammarBase>($1);
    }
    else
    {
        $$ = 0;
    }
}
;

// struct--------------------------------------------------------------
struct_def
// ----------------------------------------------------------------------
: struct_id
{
    StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>($1);
    NamespacePtr np = std::dynamic_pointer_cast<Namespace>(g_parse->currentContainer());
    if(np)
    {
         StructPtr sp = np->createStruct(ident->v);
         if(sp)
         {
             g_parse->pushContainer(sp);
             $$ = std::dynamic_pointer_cast<GrammarBase>(sp);
         }
         else
         {
             $$ = 0;
         }
    }
    else
    {
       g_parse->error("struct '" + ident->v + "' must definition in namespace");
    }
}
'{' struct_exports '}'
{
    if($2)
    {
        g_parse->popContainer();
    }
    $$ = $2;

    StructPtr st = std::dynamic_pointer_cast<Struct>($$);
    assert(st);
    if(st->getAllMemberPtr().size() == 0)
    {
        g_parse->error("struct `" + st->getSid() + "' must have at least one member");
    }
}
;

// struct name----------------------------------------------------------
struct_id
// ----------------------------------------------------------------------
: GAUSSIAN_STRUCT GAUSSIAN_IDENTIFIER
{
    $$ = $2;
}
| GAUSSIAN_STRUCT keyword
{
    StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>($2);

    g_parse->error("keyword `" + ident->v + "' cannot be used as struct name");
}
| GAUSSIAN_STRUCT error
{
    g_parse->error("abstract declarator '<anonymous struct>' used as declaration");
}
;

// struct members------------------------------------------------------
struct_exports
// ----------------------------------------------------------------------
: data_member ';' struct_exports
{

}
| data_member
{
   g_parse->error("';' missing after definition");
}
|
{
}
;

// 
// 
// data member--------------------------------------------------------------
data_member
// ----------------------------------------------------------------------
: struct_type_id
{
    $$ = std::dynamic_pointer_cast<GrammarBase>($1);
}
;

// struct member id--------------------------------------------------------------
struct_type_id
// ----------------------------------------------------------------------
: GAUSSIAN_CONST_INTEGER GAUSSIAN_REQUIRE type_id
{
    StructPtr np = std::dynamic_pointer_cast<Struct>(g_parse->currentContainer());
    if(np)
    {
        IntergerGrammarPtr iPtr = std::dynamic_pointer_cast<IntergerGrammar>($1);
        g_parse->checkTag(iPtr->v);

        TypeIdPtr tPtr  = std::dynamic_pointer_cast<TypeId>($3);
        tPtr->setRequire(iPtr->v);
        np->addTypeId(tPtr);
        $$ = std::dynamic_pointer_cast<GrammarBase>($3);
    }
    else
    {
        $$ = 0;
    }
}
| GAUSSIAN_CONST_INTEGER GAUSSIAN_REQUIRE type_id '=' const_initializer
{
    StructPtr np = std::dynamic_pointer_cast<Struct>(g_parse->currentContainer());
    if(np)
    {
        IntergerGrammarPtr iPtr = std::dynamic_pointer_cast<IntergerGrammar>($1);
        g_parse->checkTag(iPtr->v);

        TypeIdPtr tPtr   = std::dynamic_pointer_cast<TypeId>($3);
        ConstGrammarPtr sPtr = std::dynamic_pointer_cast<ConstGrammar>($5);
        g_parse->checkConstValue(tPtr, sPtr->t);

        tPtr->setRequire(iPtr->v);
        tPtr->setDefault(sPtr->v);
        np->addTypeId(tPtr);
        $$ = std::dynamic_pointer_cast<GrammarBase>($3);
    }
    else
    {
        $$ = 0;
    }
}
| GAUSSIAN_CONST_INTEGER GAUSSIAN_OPTIONAL type_id '=' const_initializer
{
    StructPtr np = std::dynamic_pointer_cast<Struct>(g_parse->currentContainer());
    if(np)
    {
        IntergerGrammarPtr iPtr = std::dynamic_pointer_cast<IntergerGrammar>($1);
        g_parse->checkTag(iPtr->v);

        TypeIdPtr tPtr   = std::dynamic_pointer_cast<TypeId>($3);
        ConstGrammarPtr sPtr = std::dynamic_pointer_cast<ConstGrammar>($5);
        g_parse->checkConstValue(tPtr, sPtr->t);

        tPtr->setOptional(iPtr->v);
        tPtr->setDefault(sPtr->v);
        np->addTypeId(tPtr);
        $$ = std::dynamic_pointer_cast<GrammarBase>($3);
    }
    else
    {
        $$ = 0;
    }
}
| GAUSSIAN_CONST_INTEGER GAUSSIAN_OPTIONAL type_id
{
    StructPtr np = std::dynamic_pointer_cast<Struct>(g_parse->currentContainer());
    if(np)
    {
        IntergerGrammarPtr iPtr = std::dynamic_pointer_cast<IntergerGrammar>($1);
        g_parse->checkTag(iPtr->v);
        TypeIdPtr tPtr = std::dynamic_pointer_cast<TypeId>($3);
        tPtr->setOptional(iPtr->v);
        np->addTypeId(tPtr);
        $$ = std::dynamic_pointer_cast<GrammarBase>($3);
    }
    else
    {
        $$ = 0;
    }
}
| GAUSSIAN_REQUIRE type_id
{
    g_parse->error("struct member need 'tag'");
}
| GAUSSIAN_OPTIONAL type_id
{
    g_parse->error("struct member need 'tag'");
}
| GAUSSIAN_CONST_INTEGER type_id
{
    g_parse->error("struct member need 'require' or 'optional'");
}
| type_id
{
    g_parse->error("struct member need 'tag' or 'require' or 'optional'");
}
;

// ----------------------------------------------------------------------
const_initializer
// ----------------------------------------------------------------------
: GAUSSIAN_CONST_INTEGER
{
    IntergerGrammarPtr intVal = std::dynamic_pointer_cast<IntergerGrammar>($1);
    ostringstream sstr;
    sstr << intVal->v;
    ConstGrammarPtr c = std::make_shared<ConstGrammar>();
    c->t = ConstGrammar::VALUE;
    c->v = sstr.str();
    $$ = c;
}
| GAUSSIAN_CONST_FLOAT
{
    FloatGrammarPtr floatVal = std::dynamic_pointer_cast<FloatGrammar>($1);
    ostringstream sstr;
    sstr << floatVal->v;
    ConstGrammarPtr c = std::make_shared<ConstGrammar>();
    c->t = ConstGrammar::VALUE;
    c->v = sstr.str();
    $$ = c;
}
| GAUSSIAN_STRING_LITERAL
{
    StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>($1);
    ConstGrammarPtr c = std::make_shared<ConstGrammar>();
    c->t = ConstGrammar::STRING;
    c->v = ident->v;
    $$ = c;
}
| GAUSSIAN_FALSE
{
    StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>($1);
    ConstGrammarPtr c = std::make_shared<ConstGrammar>();
    c->t = ConstGrammar::BOOL;
    c->v = ident->v;
    $$ = c;
}
| GAUSSIAN_TRUE
{
    StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>($1);
    ConstGrammarPtr c = std::make_shared<ConstGrammar>();
    c->t = ConstGrammar::BOOL;
    c->v = ident->v;
    $$ = c;
}
| GAUSSIAN_IDENTIFIER
{
    StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>($1);
    ConstGrammarPtr c = std::make_shared<ConstGrammar>();
    c->t = ConstGrammar::STRING;
    c->v = ident->v;
    $$ = c;
}
| scoped_name GAUSSIAN_SCOPE_DELIMITER GAUSSIAN_IDENTIFIER
{

    StringGrammarPtr scoped = std::dynamic_pointer_cast<StringGrammar>($1);
    StringGrammarPtr ident  = std::dynamic_pointer_cast<StringGrammar>($3);
    
    if (g_parse->checkEnum(ident->v) == false)
    {
        g_parse->error("error enum default value, not defined yet");
    }
    ConstGrammarPtr c = std::make_shared<ConstGrammar>();
    c->t = ConstGrammar::ENUM;
    c->v = scoped->v + "::" + ident->v;
    $$ = c;
}
;

// const--------------------------------------------------------------
const_def
// ----------------------------------------------------------------------
: GAUSSIAN_CONST type_id '=' const_initializer
{
    NamespacePtr np = std::dynamic_pointer_cast<Namespace>(g_parse->currentContainer());
    if(!np)
    {
        g_parse->error("const type must define in namespace");
    }

    TypeIdPtr t   = std::dynamic_pointer_cast<TypeId>($2);
    ConstGrammarPtr c = std::dynamic_pointer_cast<ConstGrammar>($4);
    ConstPtr cPtr = np->createConst(t, c);
    $$ = cPtr;
}
;

// type--------------------------------------------------------------
type_id
// ----------------------------------------------------------------------
: type GAUSSIAN_IDENTIFIER
{
    TypePtr type = std::dynamic_pointer_cast<Type>($1);
    StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>($2);

    TypeIdPtr typeIdPtr = std::make_shared<TypeId>(type, ident->v);

    $$ = std::dynamic_pointer_cast<GrammarBase>(typeIdPtr);
}
|type GAUSSIAN_IDENTIFIER  '[' GAUSSIAN_CONST_INTEGER ']'
{
    TypePtr type = g_parse->createVector(std::dynamic_pointer_cast<Type>($1));
    IntergerGrammarPtr iPtrSize = std::dynamic_pointer_cast<IntergerGrammar>($4);
    g_parse->checkArrayVaid(type,iPtrSize->v);
    type->setArray(iPtrSize->v);
    StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>($2);
    TypeIdPtr typeIdPtr = std::make_shared<TypeId>(type, ident->v);
    $$ = std::dynamic_pointer_cast<GrammarBase>(typeIdPtr);
}
|type '*' GAUSSIAN_IDENTIFIER  
{
    TypePtr type = g_parse->createVector(std::dynamic_pointer_cast<Type>($1));
    //IntergerGrammarPtr iPtrSize = std::dynamic_pointer_cast<IntergerGrammar>($4);
    g_parse->checkPointerVaid(type);
    type->setPointer(true);
    StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>($3);
    TypeIdPtr typeIdPtr = std::make_shared<TypeId>(type, ident->v);
    $$ = std::dynamic_pointer_cast<GrammarBase>(typeIdPtr);
}
|type GAUSSIAN_IDENTIFIER  ':' GAUSSIAN_CONST_INTEGER 
{
    TypePtr type = std::dynamic_pointer_cast<Type>($1);
    StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>($2);
    TypeIdPtr typeIdPtr = std::make_shared<TypeId>(type, ident->v);
    IntergerGrammarPtr iPtrSize = std::dynamic_pointer_cast<IntergerGrammar>($3);
    g_parse->checkArrayVaid(type,iPtrSize->v);
    $$ = std::dynamic_pointer_cast<GrammarBase>(typeIdPtr);
}
| type keyword
{
    StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>($2);
    g_parse->error("keyword `" + ident->v + "' cannot be used as data member name");
}
| type
{
    g_parse->error("missing data member name");
}
| error
{
    g_parse->error("unkown type");
}
;

// type------------------------------------------------------------------
type
// ----------------------------------------------------------------------
: type_no ':' GAUSSIAN_CONST_INTEGER 
{

    TypePtr type = std::dynamic_pointer_cast<Type>($1);
    IntergerGrammarPtr iPtrSize = std::dynamic_pointer_cast<IntergerGrammar>($3);
    g_parse->checkArrayVaid(type,iPtrSize->v);
    type->setArray(iPtrSize->v);
    $$ = type;
}
| type_no '(' ')'
{
    TypePtr type = std::dynamic_pointer_cast<Type>($1);
    type->setArray(100);
    $$ = type;
}
| type_no
{
    $$ = $1;
}
| type_no ':' error
{
   g_parse->error("array missing size");
}
;

// type------------------------------------------------------------------
type_no
// ----------------------------------------------------------------------
: GAUSSIAN_BOOL
{
    $$ = g_parse->createBuiltin(Builtin::KindBool);
}
| GAUSSIAN_BYTE
{
    $$ = g_parse->createBuiltin(Builtin::KindByte);
}
| GAUSSIAN_UNSIGNED GAUSSIAN_BYTE //unsigned char -> short
{
    $$ = g_parse->createBuiltin(Builtin::KindShort,true);
}
| GAUSSIAN_SHORT
{
    $$ = g_parse->createBuiltin(Builtin::KindShort);
}
| GAUSSIAN_UNSIGNED GAUSSIAN_SHORT
{
    $$ = g_parse->createBuiltin(Builtin::KindInt,true);
}
| GAUSSIAN_INT
{
    $$ = g_parse->createBuiltin(Builtin::KindInt);
}
| GAUSSIAN_UNSIGNED GAUSSIAN_INT
{
    $$ = g_parse->createBuiltin(Builtin::KindLong,true);
}
| GAUSSIAN_LONG
{
    $$ = g_parse->createBuiltin(Builtin::KindLong);
}
| GAUSSIAN_FLOAT
{
    $$ = g_parse->createBuiltin(Builtin::KindFloat);
}
| GAUSSIAN_DOUBLE
{
    $$ = g_parse->createBuiltin(Builtin::KindDouble);
}
| GAUSSIAN_STRING
{
    $$ = g_parse->createBuiltin(Builtin::KindString);
}
| vector
{
   $$ = std::dynamic_pointer_cast<GrammarBase>($1);
}
| map
{
   $$ = std::dynamic_pointer_cast<GrammarBase>($1);
}
| scoped_name
{
    StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>($1);
    TypePtr sp = g_parse->findUserType(ident->v);
    if(sp)
    {
        $$ = std::dynamic_pointer_cast<GrammarBase>(sp);
    }
    else
    {
        g_parse->error("'" + ident->v + "' undefined!");
    }
}
;

// vector----------------------------------------------------------------
vector
// ----------------------------------------------------------------------
: GAUSSIAN_VECTOR '<' type '>'
{
   $$ = std::dynamic_pointer_cast<GrammarBase>(g_parse->createVector(std::dynamic_pointer_cast<Type>($3)));
}
| GAUSSIAN_VECTOR '<' error
{
   g_parse->error("vector error");
}
| GAUSSIAN_VECTOR '<' type error
{
   g_parse->error("vector missing '>'");
}
| GAUSSIAN_VECTOR error
{
   g_parse->error("vector missing type");
}
;

// map----------------------------------------------------------------
map
// ----------------------------------------------------------------------
: GAUSSIAN_MAP '<' type ',' type '>'
{
   $$ = std::dynamic_pointer_cast<GrammarBase>(g_parse->createMap(std::dynamic_pointer_cast<Type>($3), std::dynamic_pointer_cast<Type>($5)));
}
| GAUSSIAN_MAP '<' error
{
   g_parse->error("map error");
}
;

// ----------------------------------------------------------------------
scoped_name
// ----------------------------------------------------------------------
: GAUSSIAN_IDENTIFIER
{
}
| GAUSSIAN_SCOPE_DELIMITER GAUSSIAN_IDENTIFIER
{
    StringGrammarPtr ident = std::dynamic_pointer_cast<StringGrammar>($2);
    ident->v = "::" + ident->v;
    $$ = std::dynamic_pointer_cast<GrammarBase>(ident);
}
| scoped_name GAUSSIAN_SCOPE_DELIMITER GAUSSIAN_IDENTIFIER
{
    StringGrammarPtr scoped = std::dynamic_pointer_cast<StringGrammar>($1);
    StringGrammarPtr ident  = std::dynamic_pointer_cast<StringGrammar>($3);
    scoped->v += "::";
    scoped->v += ident->v;
    $$ = std::dynamic_pointer_cast<GrammarBase>(scoped);
}
;

// key----------------------------------------------------------------
keyword
// ----------------------------------------------------------------------
: GAUSSIAN_STRUCT
{
}
| GAUSSIAN_ROS_PARAMS
{
}
| GAUSSIAN_VOID
{
}
| GAUSSIAN_BOOL
{
}
| GAUSSIAN_BYTE
{
}
| GAUSSIAN_SHORT
{
}
| GAUSSIAN_INT
{
}
| GAUSSIAN_FLOAT
{
}
| GAUSSIAN_DOUBLE
{
}
| GAUSSIAN_STRING
{
}
| GAUSSIAN_VECTOR
{
}
| GAUSSIAN_KEY
{
}
| GAUSSIAN_MAP
{
}
| GAUSSIAN_NAMESPACE
{
}
| GAUSSIAN_ROS_NAMESPACE
{
}
| GAUSSIAN_PARAM_CALLBACK
{
}
| GAUSSIAN_INTERFACE
{
}
| GAUSSIAN_OUT
{
}
| GAUSSIAN_REQUIRE
{
}
| GAUSSIAN_OPTIONAL
{
}
| GAUSSIAN_CONST_INTEGER
{
}
| GAUSSIAN_CONST_FLOAT
{
}
| GAUSSIAN_FALSE
{
}
| GAUSSIAN_TRUE
{
}
| GAUSSIAN_STRING_LITERAL
{
}
| GAUSSIAN_CONST
{
}
| GAUSSIAN_ENUM
{
}
| GAUSSIAN_UNSIGNED
{
}
;

%%


