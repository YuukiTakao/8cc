#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "9cc.h"

Token *token;

char *user_input;


bool starts_with(char *p, char *q) {
	return memcmp(p, q, strlen(q)) == 0;
}

// 新しいトークンを作成してcurに繋げる
Token *new_token(TokenKind kind, Token *cur, char *str, int len) {
	Token *tok = calloc(1, sizeof(Token));
	tok->kind = kind;
	tok->str = str;
	tok->len = len;
	cur->next = tok;
	return tok;
}

Token *tokenize(char *p) {
	Token head;
	head.next = NULL;
	Token *cur = &head;

	while(*p) {
		// 空白文字をスキップ
		if (isspace(*p)) {
			p++;
			continue;
		}

		// Multi-letter punctuator
		if (starts_with(p, "==") ||
			starts_with(p, "!=") ||
			starts_with(p, "<=") ||
			starts_with(p, ">=")) {
			cur = new_token(TK_RESERVED, cur, p, 2);
			p += 2;
			continue;
		}

		// Single-letter punctuator
		if (strchr("+-*/()<>", *p)) {
			cur = new_token(TK_RESERVED, cur, p++, 1);
			continue;
		}

		// Integer literal
		if (isdigit(*p)) {
			cur = new_token(TK_NUM, cur, p, 0);
			char *q = p;
			cur->val = strtol(p, &p, 10);
			cur->len = p - q;
			continue;
		}

		error_at(token->str ,"トークナイズできません");
	}

	new_token(TK_EOF, cur, p, 1);
	return head.next;
}

int main(int argc, char **argv) {
	if (argc != 2) {
		error("引数の個数が正しくありません");
		return 1;
	}

	// トークナイズする
	user_input = argv[1];
	token = tokenize(argv[1]);
	Node *node = expr(); 

	// アセンブリの前半を出力
	printf(".intel_syntax noprefix\n");
	printf(".global main\n");
	printf("main:\n");

	gen(node);

	printf("	pop rax\n");
	printf("	ret\n");
	return 0;
}