#include <stdbool.h>

typedef enum {
	ND_ADD, // +
	ND_SUB, // -
	ND_MUL, // *
	ND_DIV, // /
	ND_NUM, // Integer literals
	ND_LT,	// <
	ND_LTE,	// <=
	ND_EQ,	// ==
	ND_NE,	// !=
} NodeKind;

typedef struct Node Node;

struct Node {
	NodeKind kind;	// ノードの型
	Node *lhs;		// 左辺
	Node *rhs;		// 右辺
	int val;		// kindがND_NUMの場合のみ使う
};

Node *expr();
Node *equality();
Node *relational();
Node *add();
Node *mul();
Node *unary();
bool consume(char *op);
Node *primary();
void expect(char *op);
int expect_number();


typedef enum {
	TK_RESERVED,
	TK_NUM,
	TK_EOF,
} TokenKind;

typedef struct Token Token;

struct Token {
	TokenKind kind;
	Token *next;
	int val;
	char *str;
	int len;
};

// 現在着目しているトークン
extern Token *token;

extern char *user_input;


void gen(Node *node);

void error(char *fmt, ...);

void error_at(char *loc, char *fmt, ...);