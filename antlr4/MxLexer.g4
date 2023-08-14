lexer grammar MxLexer;
//词法全部大写，语法全部小写
//需要注意的是，Lexer中的定义顺序靠前则匹配优先级更高
//被标记为skip的规则将被完全忽略，它们的匹配结果不会成为语法树的一部分
//默认的.*是贪婪的，我们可以在 * 后面加上 ?，形成 *?。这表示匹配前面的元素零次或多次，但尽可能少地匹配。

//Comments and Whitespace
Whitespace
    :   [ \t]+
        -> skip
    ;

Newline
    :   (   '\r' '\n'?
        |   '\n'
        )
        -> skip
    ;

BlockComment
    :   '/*' .*? '*/'
        -> skip
    ;

LineComment
    :   '//' ~[\r\n]*
        -> skip
    ;

//operators
OpAdd: '+';
OPSub: '-';
OPMul: '*';
OpDiv: '/';
OpMod: '%';
Greater: '>';
Less: '<';
GreaterEqual: '>=';
LessEqual: '<=';
NotEqual: '!=';
Equal: '==';
LogicAnd: '&&';
LogicOr: '||';
LogicNot: '!';
RightShift: '>>';
LeftShift: '<<';
BitAnd: '&';
BitOr: '|';
BitXor: '^';
BitNegation: '~';
OpAssign: '=';
OpIncrement: '++';
OpDecrement: '--';
OpMemberAccess: '.';
OpenParen: '(';
CloseParen: ')';
OpenBracket: '[';
CloseBracket: ']';

//separator
OpenBrace: '{';
CloseBrace: '}';
SemiColon: ';';
Comma: ',';
QuestionMark: '?';
Colon: ':';

//keyword
Void:     'void';
Bool:     'bool';
Int:      'int';
String:   'string';
New:      'new';
Class:    'class';
Null:     'null';
True:     'true';
False:    'false';
This:     'this';
If:       'if';
Else:     'else';
For:      'for';
While:    'while';
Break:    'break';
Continue: 'continue';
Return:   'return';

// fragments
fragment Digit: [0-9];
fragment NoneZeroDigit: [1-9];
fragment Letter: [a-zA-Z];
fragment IdentifierLetter: [a-zA-Z0-9_];
fragment EscapedChar: '\\' [n\\"];
fragment StringLetter : ~[\u0000-\u001F\\"] | EscapedChar;

//注意，这同样也可以匹配return等关键词，ANTLR处理这种歧义的方式是：选择所有备选分支中的第一条，所以ID标识符应该放在关键字等定义之后
// Identifier
Identifier : Letter IdentifierLetter*;

// Literals
StringLiteral: '"' StringLetter* '"';
LogicalLiteral: True | False;
IntegerLiteral: ('0' | NoneZeroDigit Digit*);
