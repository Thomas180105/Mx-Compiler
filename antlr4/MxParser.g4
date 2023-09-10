//参考网站：https://blog.csdn.net/qq_37771475/article/details/106528661
//词法全部大写，语法全部小写
//最抽象的放在最前面，最具象的放在最后面，否则可能抽象层级低的组件之间覆盖掉了抽象层级高的
//列举越先的规则优先级越高。结合性默认为左结合，需使用右结合的时候需使用<assoc=right>
//书写op=的作用是可以在对应类型的node中调用op来直接访问对应的值
//不需要在.g4文件中额外定义。ANTLR会根据上下文自动识别和处理EOF标记

parser grammar MxParser;//这行代码不是强制要求，但根据具体情况，它可以提供更好的可读性和清晰度
options {
  tokenVocab=MxLexer;
}

program: declaration* EOF;

//抽象层级最高的组件
declaration
    : variableDeclaration
    | functionDeclaration
    | classDeclaration
    ;

functionDeclaration: typename identifier '(' functionDeclList? ')' body=suiteStatement;
functionDeclList: (functionDeclPair ',')* functionDeclPair;
functionDeclPair: typename identifier;
functionCallList: (expression ',')* expression;

classDeclaration: 'class' identifier '{' classComponents* '}' ';';
classComponents
    : variableDeclaration
    | functionDeclaration
    | constructorDeclaration
    ;

constructorDeclaration: identifier '(' ')' body=suiteStatement;

wrapper: suiteStatement | statement;
suiteStatement: '{' statement* '}';

statement
    : variableDeclaration
    | expresionStatement
    | branchStatement
    | loopStatement
    | controlFlowStatement
    | suiteStatement
    | emptyStatement
    ;

variableDeclaration: typename (initDeclarator ',')* initDeclarator ';'; //have to split the initDeclarator part, if not, you will have problem building the AST
initDeclarator: identifier ('=' initialValue=expression)?;

expresionStatement: expression? ';';
branchStatement: If '(' condition=expression ')' ifWrapper=wrapper (Else elseWrapper=wrapper)?;

loopStatement
    : While '(' conditon=expression ')' body=wrapper #WhileLoop
    | For '(' init=variableDeclaration condition=expression? ';' step=expression? ')' body=wrapper # NormalForLoop
    | For '(' init=expresionStatement condition=expression? ';' step=expression? ')' body=wrapper     # ExprForLoop
    ;

controlFlowStatement
    : returnStatement   # ReturnStmt
    | breakStatement    # BreakStmt
    | continueStatement # ContinueStmt
    ;
returnStatement: Return expression? ';';
breakStatement: Break ';';
continueStatement: Continue ';';

emptyStatement: ';';

// literalExpression
// : StringLiteral
// | LogicalLiteral
// | IntegerLiteral
// | This
// | Null
// ;

logicalLiteral: True | False;
literalExpression
: StringLiteral
| logicalLiteral //实验中发现直接写为('true' | 'false')也可以
| IntegerLiteral
| Null
;

typename
    : builtInTypename  # BuiltInType
    | identifier       # ClassType
    | typename '[' ']' # ArrayType
    ;

newTypename
    : identifier newArrayExpr+ newArrayEmpty* (flag = newArrayExpr*)      # NewClassArray
    | builtInTypename newArrayExpr+ newArrayEmpty* (flag = newArrayExpr*) # NewBuildInArray
    | identifier                                     # NewClass
    ;

newArrayExpr: '[' expression ']';
newArrayEmpty: '[' ']';

identifier: Identifier;

expression
    : '(' expression ')'                                               # ParenExpr
    | expression '(' functionCallList? ')'                             # FunctionCall
    | expression '.' identifier                                        # MemberExpr
    | expression '[' expression ']'                                    # ArrayExpr
    | newExpression                                                    # newExpr
    | lhs=expression op=('++' | '--')                                  # PostfixOpExpr
    | <assoc=right>  op=('++' | '--') rhs=expression                   # PrefixOpExpr
    | <assoc=right>  op=('!' | '~' | '+' | '-')                rhs=expression # UnaryExpr
    | lhs=expression op=('*' | '/' | '%')                      rhs=expression # BinaryExpr
    | lhs=expression op=('+' | '-')                            rhs=expression # BinaryExpr
    | lhs=expression op=('<<' | '>>')                          rhs=expression # BinaryExpr
    | lhs=expression op=('<' | '>'| '<=' | '>=' | '!=' | '==') rhs=expression # BinaryExpr
    | lhs=expression op='&'                                    rhs=expression # BinaryExpr
    | lhs=expression op='^'                                    rhs=expression # BinaryExpr
    | lhs=expression op='|'                                    rhs=expression # BinaryExpr
    | lhs=expression op='&&'                                   rhs=expression # BinaryExpr
    | lhs=expression op='||'                                   rhs=expression # BinaryExpr
    | <assoc=right> expression '?' expression ':' expression       # TernaryExpr
    | <assoc=right> lhs=expression '='                      rhs=expression # AssignExpr
    | literalExpression                                                # LiteralExpr
    | (identifier | This)                                                       # IdentifierExpr
    ;

newExpression: 'new' newTypename ('(' ')')?;

builtInTypename
    : Void
    | Bool
    | Int
    | String
    ;