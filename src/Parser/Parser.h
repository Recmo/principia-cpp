#pragma once
#include <fixups.h>
#include <Parser/SourceProperty.h>
#include "ParseTree.h"
namespace quex { class QuexParser; class Token; }

class Parser
{
public:
	Parser();
	
	Parser& parse(const string& filename);
	
	ParseTree* tree() { return _tree; }
	
private:
	typedef quex::Token Token;
	string _filename;
	quex::QuexParser* _parser;
	quex::Token* _token;
	ParseTree* _tree;
	ParseTree::Statement* _statement;
	bool _unread;
	
	void readNext();
	void unread();
	uint32 token();
	string lexeme();
	SourceProperty source(bool hasLexeme = true);
	
	ParseTree* parseFile();
	ParseTree::Statement* parseStatement();
	ParseTree::Statement* parseInlineStatement();
	ParseTree::Scope* parseScope();
	ParseTree::Node* parseExpression();
	ParseTree::Identifier* parseIdentifier();
	ParseTree::Constant* parseNumber();
	ParseTree::Constant* parseQuotation();
	
	void parseFailure(string location = string());
};
