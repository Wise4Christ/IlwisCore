/** \file
 *  This C header file was generated by $ANTLR version 3.4
 *
 *     -  From the grammar source file : D:\\Projects\\Ilwis\\Ilwis4\\projects\\IlwisCore\\ilwisscript\\parserlexer\\ilwisscript.g
 *     -                            On : 2016-04-22 11:46:41
 *     -                for the parser : ilwisscriptParserParser
 *
 * Editing it, at least manually, is not wise.
 *
 * C language generator and runtime by Jim Idle, jimi|hereisanat|idle|dotgoeshere|ws.
 *
 *
 * The parser 
ilwisscriptParser

has the callable functions (rules) shown below,
 * which will invoke the code for the associated rule in the source grammar
 * assuming that the input stream is pointing to a token/text stream that could begin
 * this rule.
 *
 * For instance if you call the first (topmost) rule in a parser grammar, you will
 * get the results of a full parse, but calling a rule half way through the grammar will
 * allow you to pass part of a full token stream to the parser, such as for syntax checking
 * in editors and so on.
 *
 * The parser entry points are called indirectly (by function pointer to function) via
 * a parser context typedef pilwisscriptParser, which is returned from a call to ilwisscriptParserNew().
 *
 * The methods in pilwisscriptParser are  as follows:
 *
 *  - 
 ASTNode *
      pilwisscriptParser->script(pilwisscriptParser)
 *  - 
 ASTNode *
      pilwisscriptParser->scriptLine(pilwisscriptParser)
 *  - 
 ASTNode *
      pilwisscriptParser->statement(pilwisscriptParser)
 *  - 
 SelectNode *
      pilwisscriptParser->selectExpr(pilwisscriptParser)
 *  - 
 QString
      pilwisscriptParser->sources(pilwisscriptParser)
 *  - 
 void
      pilwisscriptParser->defineStatement(pilwisscriptParser)
 *  - 
 AssignmentNode *
      pilwisscriptParser->assignmentStatement(pilwisscriptParser)
 *  - 
 OutParametersNode *
      pilwisscriptParser->outParameters(pilwisscriptParser)
 *  - 
 ParametersNode *
      pilwisscriptParser->actualParameters(pilwisscriptParser)
 *  - 
 TermNode *
      pilwisscriptParser->term(pilwisscriptParser)
 *  - 
 Selector *
      pilwisscriptParser->selector(pilwisscriptParser)
 *  - 
 TermNode *
      pilwisscriptParser->negation(pilwisscriptParser)
 *  - 
 TermNode *
      pilwisscriptParser->unary(pilwisscriptParser)
 *  - 
 MultiplicationNode *
      pilwisscriptParser->mult(pilwisscriptParser)
 *  - 
 AddNode *
      pilwisscriptParser->add(pilwisscriptParser)
 *  - 
 RelationNode *
      pilwisscriptParser->relation(pilwisscriptParser)
 *  - 
 ExpressionNode *
      pilwisscriptParser->expression(pilwisscriptParser)
 *  - 
 CommandNode *
      pilwisscriptParser->commandStatement(pilwisscriptParser)
 *  - 
 FunctionStatementNode *
      pilwisscriptParser->functionStatement(pilwisscriptParser)
 *  - 
 WhileNode *
      pilwisscriptParser->whileStatement(pilwisscriptParser)
 *  - 
 BreakNode *
      pilwisscriptParser->breakStatement(pilwisscriptParser)
 *  - 
 ASTNode *
      pilwisscriptParser->formatPart(pilwisscriptParser)
 *  - 
 ASTNode *
      pilwisscriptParser->formatters(pilwisscriptParser)
 *  - 
 ASTNode *
      pilwisscriptParser->formatter(pilwisscriptParser)
 *  - 
 void
      pilwisscriptParser->grouper(pilwisscriptParser)
 *  - 
 void
      pilwisscriptParser->reintepreter(pilwisscriptParser)
 *  - 
 void
      pilwisscriptParser->idlist(pilwisscriptParser)
 *  - 
 Formatter *
      pilwisscriptParser->dataFormatter(pilwisscriptParser)
 *  - 
 QString
      pilwisscriptParser->datatype(pilwisscriptParser)
 *  - 
 DomainFormatter *
      pilwisscriptParser->domainFormatter(pilwisscriptParser)
 *  - 
 ValueRangeNode *
      pilwisscriptParser->valrangePart(pilwisscriptParser)
 *  - 
 Ifnode *
      pilwisscriptParser->ifStatement(pilwisscriptParser)
 *  - 
 ReturnNode *
      pilwisscriptParser->returnStatement(pilwisscriptParser)
 *
 * The return type for any particular rule is of course determined by the source
 * grammar file.
 */
// [The "BSD license"]
// Copyright (c) 2005-2009 Jim Idle, Temporal Wave LLC
// http://www.temporal-wave.com
// http://www.linkedin.com/in/jimidle
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
// 3. The name of the author may not be used to endorse or promote products
//    derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
// THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef	_ilwisscriptParser_H
#define _ilwisscriptParser_H

#include <QString>
#include <QStringList>
#include <QHash>
#include "kernel.h"
#include "ilwisdata.h"
#include "geometries.h"
#include "symboltable.h"
#include "astnode.h"
#include "idnode.h"
#include "scriptnode.h"
#include "operationnode.h"
#include "expressionnode.h"
#include "outparametersnode.h"
#include "assignmentnode.h"
#include "scriptlinenode.h"
#include "parametersNode.h"
#include "selectornode.h"
#include "geos/geom/Coordinate.h"
#include "ilwiscoordinate.h"
#include "selectnode.h"
#include "termnode.h"
#include "variableNode.h"
#include "returnnode.h"
#include "functionnode.h"
#include "multiplicationnode.h"
#include "addnode.h"
#include "relationnode.h"
#include "commandnode.h"
#include "whilenode.h"
#include "breaknode.h"
#include "valuerangenode.h"
#include "domainformatter.h"
#include "ifnode.h"
#include "formatter.h"
#include "functionstatementnode.h"
 
using namespace Ilwis;

/* =============================================================================
 * Standard antlr3 C runtime definitions
 */
#include    <antlr3.h>

/* End of standard antlr 3 runtime definitions
 * =============================================================================
 */

#ifdef __cplusplus
extern "C" {
#endif

// Forward declare the context typedef so that we can use it before it is
// properly defined. Delegators and delegates (from import statements) are
// interdependent and their context structures contain pointers to each other
// C only allows such things to be declared if you pre-declare the typedef.
//
typedef struct ilwisscriptParser_Ctx_struct ilwisscriptParser, * pilwisscriptParser;



#ifdef	ANTLR3_WINDOWS
// Disable: Unreferenced parameter,							- Rules with parameters that are not used
//          constant conditional,							- ANTLR realizes that a prediction is always true (synpred usually)
//          initialized but unused variable					- tree rewrite variables declared but not needed
//          Unreferenced local variable						- lexer rule declares but does not always use _type
//          potentially unitialized variable used			- retval always returned from a rule
//			unreferenced local function has been removed	- susually getTokenNames or freeScope, they can go without warnigns
//
// These are only really displayed at warning level /W4 but that is the code ideal I am aiming at
// and the codegen must generate some of these warnings by necessity, apart from 4100, which is
// usually generated when a parser rule is given a parameter that it does not use. Mostly though
// this is a matter of orthogonality hence I disable that one.
//
#pragma warning( disable : 4100 )
#pragma warning( disable : 4101 )
#pragma warning( disable : 4127 )
#pragma warning( disable : 4189 )
#pragma warning( disable : 4505 )
#pragma warning( disable : 4701 )
#endif

/** Context tracking structure for 
ilwisscriptParser

 */
struct ilwisscriptParser_Ctx_struct
{
    /** Built in ANTLR3 context tracker contains all the generic elements
     *  required for context tracking.
     */
    pANTLR3_PARSER   pParser;

     ASTNode *
     (*script)	(struct ilwisscriptParser_Ctx_struct * ctx);

     ASTNode *
     (*scriptLine)	(struct ilwisscriptParser_Ctx_struct * ctx);

     ASTNode *
     (*statement)	(struct ilwisscriptParser_Ctx_struct * ctx);

     SelectNode *
     (*selectExpr)	(struct ilwisscriptParser_Ctx_struct * ctx);

     QString
     (*sources)	(struct ilwisscriptParser_Ctx_struct * ctx);

     void
     (*defineStatement)	(struct ilwisscriptParser_Ctx_struct * ctx);

     AssignmentNode *
     (*assignmentStatement)	(struct ilwisscriptParser_Ctx_struct * ctx);

     OutParametersNode *
     (*outParameters)	(struct ilwisscriptParser_Ctx_struct * ctx);

     ParametersNode *
     (*actualParameters)	(struct ilwisscriptParser_Ctx_struct * ctx);

     TermNode *
     (*term)	(struct ilwisscriptParser_Ctx_struct * ctx);

     Selector *
     (*selector)	(struct ilwisscriptParser_Ctx_struct * ctx);

     TermNode *
     (*negation)	(struct ilwisscriptParser_Ctx_struct * ctx);

     TermNode *
     (*unary)	(struct ilwisscriptParser_Ctx_struct * ctx);

     MultiplicationNode *
     (*mult)	(struct ilwisscriptParser_Ctx_struct * ctx);

     AddNode *
     (*add)	(struct ilwisscriptParser_Ctx_struct * ctx);

     RelationNode *
     (*relation)	(struct ilwisscriptParser_Ctx_struct * ctx);

     ExpressionNode *
     (*expression)	(struct ilwisscriptParser_Ctx_struct * ctx);

     CommandNode *
     (*commandStatement)	(struct ilwisscriptParser_Ctx_struct * ctx);

     FunctionStatementNode *
     (*functionStatement)	(struct ilwisscriptParser_Ctx_struct * ctx);

     WhileNode *
     (*whileStatement)	(struct ilwisscriptParser_Ctx_struct * ctx);

     BreakNode *
     (*breakStatement)	(struct ilwisscriptParser_Ctx_struct * ctx);

     ASTNode *
     (*formatPart)	(struct ilwisscriptParser_Ctx_struct * ctx);

     ASTNode *
     (*formatters)	(struct ilwisscriptParser_Ctx_struct * ctx);

     ASTNode *
     (*formatter)	(struct ilwisscriptParser_Ctx_struct * ctx);

     void
     (*grouper)	(struct ilwisscriptParser_Ctx_struct * ctx);

     void
     (*reintepreter)	(struct ilwisscriptParser_Ctx_struct * ctx);

     void
     (*idlist)	(struct ilwisscriptParser_Ctx_struct * ctx);

     Formatter *
     (*dataFormatter)	(struct ilwisscriptParser_Ctx_struct * ctx);

     QString
     (*datatype)	(struct ilwisscriptParser_Ctx_struct * ctx);

     DomainFormatter *
     (*domainFormatter)	(struct ilwisscriptParser_Ctx_struct * ctx);

     ValueRangeNode *
     (*valrangePart)	(struct ilwisscriptParser_Ctx_struct * ctx);

     Ifnode *
     (*ifStatement)	(struct ilwisscriptParser_Ctx_struct * ctx);

     ReturnNode *
     (*returnStatement)	(struct ilwisscriptParser_Ctx_struct * ctx);
    // Delegated rules

    const char * (*getGrammarFileName)();
    void            (*reset)  (struct ilwisscriptParser_Ctx_struct * ctx);
    void	    (*free)   (struct ilwisscriptParser_Ctx_struct * ctx);
};

// Function protoypes for the constructor functions that external translation units
// such as delegators and delegates may wish to call.
//
ANTLR3_API pilwisscriptParser ilwisscriptParserNew         (
pANTLR3_COMMON_TOKEN_STREAM
 instream);
ANTLR3_API pilwisscriptParser ilwisscriptParserNewSSD      (
pANTLR3_COMMON_TOKEN_STREAM
 instream, pANTLR3_RECOGNIZER_SHARED_STATE state);

/** Symbolic definitions of all the tokens that the 
parser
 will work with.
 * \{
 *
 * Antlr will define EOF, but we can't use that as it it is too common in
 * in C header files and that would be confusing. There is no way to filter this out at the moment
 * so we just undef it here for now. That isn't the value we get back from C recognizers
 * anyway. We are looking for ANTLR3_TOKEN_EOF.
 */
#ifdef	EOF
#undef	EOF
#endif
#ifdef	Tokens
#undef	Tokens
#endif
#define EOF      -1
#define T__13      13
#define T__14      14
#define T__15      15
#define T__16      16
#define T__17      17
#define T__18      18
#define T__19      19
#define T__20      20
#define T__21      21
#define T__22      22
#define T__23      23
#define T__24      24
#define T__25      25
#define T__26      26
#define T__27      27
#define T__28      28
#define T__29      29
#define T__30      30
#define T__31      31
#define T__32      32
#define T__33      33
#define T__34      34
#define T__35      35
#define T__36      36
#define T__37      37
#define T__38      38
#define T__39      39
#define T__40      40
#define T__41      41
#define T__42      42
#define T__43      43
#define T__44      44
#define T__45      45
#define T__46      46
#define T__47      47
#define T__48      48
#define T__49      49
#define T__50      50
#define T__51      51
#define T__52      52
#define T__53      53
#define T__54      54
#define T__55      55
#define T__56      56
#define T__57      57
#define T__58      58
#define T__59      59
#define T__60      60
#define T__61      61
#define T__62      62
#define T__63      63
#define T__64      64
#define COMMENT      4
#define EOL      5
#define ESC_SEQ      6
#define EXPONENT      7
#define FLOAT      8
#define ID      9
#define INT      10
#define STRING      11
#define WS      12
#ifdef	EOF
#undef	EOF
#define	EOF	ANTLR3_TOKEN_EOF
#endif

#ifndef TOKENSOURCE
#define TOKENSOURCE(lxr) lxr->pLexer->rec->state->tokSource
#endif

/* End of token definitions for ilwisscriptParser
 * =============================================================================
 */
/** } */

#ifdef __cplusplus
}
#endif

#endif

/* END - Note:Keep extra line feed to satisfy UNIX systems */
