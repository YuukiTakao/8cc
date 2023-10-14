# Cコンパイラ作成

> https://www.sigbus.info/compilerbook#

上記を参考にCコンパイラを作成する


## EBNF

```
expr    = mul ("+" mul | "-" mul)*
mul     = unary ("*" unary | "/" unary)*
unary   = ("+" | "-")? primary
primary = num | "(" expr ")"
```

### 記号の意味

- `X*` : Xは0回以上の繰り返し
- `X?` : Xは0回または1回