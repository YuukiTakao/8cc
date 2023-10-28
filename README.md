# Cコンパイラ作成

> https://www.sigbus.info/compilerbook#

上記を参考にCコンパイラを作成する

## EBNF (extended Backus–Naur form, Japan: 生成文法)

```
expr       = equality
equality   = relational ("==" relational | "!=" relational)*
relational = add ("<" add | "<=" add | ">" add | ">=" add)*
add        = mul ("+" mul | "-" mul)*
mul        = unary ("*" unary | "/" unary)*
unary      = ("+" | "-")? primary
primary    = num | "(" expr ")"
```

### 記号の意味

- `X*` : Xは0回以上の繰り返し
- `X?` : Xは0回または1回