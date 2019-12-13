#include <iostream>
using namespace std;

#define OK 1 // OK跟ERROR表示执行某些任务的成功与否
#define ERROR 0
#define TRUE 1 // TRUE跟FALSE表示某些函数执行判断结果的符合与否
#define FALSE 0
//using ElemType = int;
using ElemType = char;
using Status = int; // Status是函数的类型，其值是函数结果状态代码，即OK与ERROR
#define MAXSIZE 20
struct SqStack{
    ElemType data[MAXSIZE];
    int top;
};

Status InitStack(SqStack &S) 
{   
    S.top = -1; // 栈顶元素指向栈内最顶上的元素，空栈时top=-1
    return OK;
}

Status StackEmpty(SqStack S) 
{
    if (S.top == -1) 
        return TRUE;
    else 
        return FALSE;
}

// 初始条件：顺序栈L已存在，1<=i<=StackLength(L)
// 操作结果：插入元素e为新的栈顶元素
Status Push(SqStack &S, ElemType e)
{
    if (S.top == MAXSIZE - 1)
        return ERROR;
    ++S.top;
    S.data[S.top] = e;

    return OK;
}

// 初始条件：顺序栈L已存在，1<=i<=StackLength(L)
// 操作结果：删除栈S中栈顶元素，并用e返回其值。
Status Pop(SqStack &S, ElemType &e)
{
    if (S.top == -1)
        return ERROR;
    e = S.data[S.top];
    --S.top;

    return OK;
}

inline int StackLength(SqStack S) 
{
    return S.top+1;
}

Status GetTop(SqStack S, ElemType &e)
{
    if (S.top == -1)
        return ERROR; 
    else {
        e = S.data[S.top];
        return OK;
    }
}

// ******************下面的代码跟上面的一模一样都是顺序栈，唯一的区别就是data的类型一个是char一个是int，因为我不知道怎么直接修改data的类型，就是那种类似重载的操作，所以只好重新来一遍 **********
struct SqStack_int{
    int data[MAXSIZE];
    int top;
};

Status InitStack(SqStack_int &S) 
{   
    S.top = -1; // 栈顶元素指向栈内最顶上的元素，空栈时top=-1
    return OK;
}

Status StackEmpty(SqStack_int S) 
{
    if (S.top == -1) 
        return TRUE;
    else 
        return FALSE;
}

// 初始条件：顺序栈L已存在，1<=i<=StackLength(L)
// 操作结果：插入元素e为新的栈顶元素
Status Push(SqStack_int &S, int e)
{
    if (S.top == MAXSIZE - 1)
        return ERROR;
    ++S.top;
    S.data[S.top] = e;

    return OK;
}

// 初始条件：顺序栈L已存在，1<=i<=StackLength(L)
// 操作结果：删除栈S中栈顶元素，并用e返回其值。
Status Pop(SqStack_int &S, int &e)
{
    if (S.top == -1)
        return ERROR;
    e = S.data[S.top];
    --S.top;

    return OK;
}

inline int StackLength(SqStack_int S) 
{
    return S.top+1;
}

Status GetTop(SqStack_int S, int &e)
{
    if (S.top == -1)
        return ERROR; 
    else {
        e = S.data[S.top];
        return OK;
    }
}
// ***************** SqStack_int的代码结束 *************

struct element{
    char t; // type，'c'表示符号，'i'表示数字
    int val;
};

struct expression {
    element data[MAXSIZE];
    int length = 0;
};

void add(expression &exp, char t, int val)
{
    exp.data[exp.length].t = t;
    exp.data[exp.length].val = val;
    ++exp.length;
}

int prior(char c) // 进来的时候可能会有int到char的强制转换，不会产生错误
{
    if (c == '+' || c == '-')
        return 0;
    else if (c == 'x' || c == '/')
        return 1;
    else if (c == '(')
        return -1;
}

void print(expression exp)
{
    for (int i = 0; i != exp.length; ++i)
        if (exp.data[i].t == 'c')
            printf("%c ", exp.data[i].val);
        else if (exp.data[i].t == 'i')
            printf("%d ", exp.data[i].val); 
    printf("\n");
}

            
int main() {
    int n;
    cin >> n;
    int cnt = 1;
    int num = 0;
    char c;
    expression midfix;
    for (int cnt = 0; cnt != n; ++cnt) {
        midfix.length = 0;
        for (int cnt1 = 0; cnt1 != 7; ++cnt1) {
            //读取输入，保存为中缀表达式
            cin >> c;
            if (c >= '0' && c <= '9')
                num = num * 10 + int(c - 48);
            else {
                if (num != 0) {
                    add(midfix, 'i', num);
                    num = 0;            
                }
                add(midfix, 'c', c);
            }
            
        }
        if (num != 0) {
            add(midfix, 'i', num);
            num = 0;
        }            
        //print(midfix);
         
        // 变中缀表达式为后缀表达式（后缀表达式中不含有括号）
        // 规则：从左到右遍历中缀表达式的每个数字和符号
        // 若是数字，则将其加入后缀表达式；
        // 若是右括号，则栈顶元素依次出栈并输出，直到栈内的一个左括号出栈；
        // 若是左括号，则直接进栈；
        // 若是四则运算符号，如果其优先级高于栈顶符号（乘除优先于加减），则直接进栈；
            // 如果其优先级不高于栈顶符号，则不断将栈顶元素弹出并加入后缀表达式，直到遇到优先级比当前符号还要低的符号时停止弹出（那个优先级更低的符号不弹出），然后将当前符号进栈；（在这里只有四则运算，优先级低于栈顶符号的情况只会发生在+-遇到*/，而并没有比+-优先级更低的符号，所以在这里相当于会把栈内元素全部输出）
        // 如此往复一直到中缀表达式遍历结束，将栈内元素弹出并加入后缀表达式，得到最终的后缀表达式。
        
        SqStack S;
        InitStack(S);
        expression postfix;
        ElemType e;
        for (int i = 0; i != midfix.length; ++i) {
            if (midfix.data[i].t == 'i') { // 数字
                add(postfix, 'i', midfix.data[i].val);
            }
            else if (midfix.data[i].val == ')') { // 右括号
                // 栈顶元素依次出栈并输出，直到栈内的一个左括号出栈；                
                Pop(S, e);
                while (e != '(') {
                    add(postfix, 'c', e);
                    Pop(S, e);
                }
            }
            else if (midfix.data[i].val == '(') { // 左括号
                Push(S, midfix.data[i].val); 
            }
            else { // 四则运算符号
                if (StackLength(S) == 0) { // 栈为空就直接插入了，没啥好比较的
                    Push(S, midfix.data[i].val);
                    continue;
                }
                GetTop(S, e);
                if (prior(midfix.data[i].val) <= prior(e)) { // 四则运算符号或左括号
                    // 不断将栈顶元素弹出，直到遇到优先级比当前符号还要低的符号时停止弹出（那个优先级更低的符号不弹出）        
                    while (1) {
                        if ( prior(midfix.data[i].val) > prior(e) || e == '(' || StackLength(S) == 0) // 只是觉得继续while循环的判断条件不方便理解，所以对它取了逆否命题作为break的条件
                            break;
                        Pop(S, e);
                        add(postfix, 'c', e);
                        GetTop(S, e);
                    }
                    Push(S, midfix.data[i].val);
                } else // 优先级高于栈顶符号
                    Push(S, midfix.data[i].val);  
            }
        }
        while (StackLength(S) != 0) { // 中缀表达式遍历结束，将栈内元素弹出并加入后缀表达式
            Pop(S, e);
            add(postfix, 'c', e);
        }
      //  printf("postfix.length: %d \n", postfix.length);
        
        // 计算后缀表达式的值
        // 规则：从左到右遍历表达式的每个数字和符号，遇到是数字就进栈，遇到是符号，就将处于栈顶的两个数字出栈，进行运算，运算结果进栈，一直到最终获得结果。
        SqStack_int S_i;
        InitStack(S_i);    
        int i1, i2;
        for (int i = 0; i != postfix.length; ++i) {
            if (postfix.data[i].t == 'i') // 数字直接进栈
                Push(S_i, postfix.data[i].val);
            else { // 符号，将处于栈顶的两个数字出栈
                Pop(S_i, i2);
                Pop(S_i, i1);
                //printf("i1: %d, i2: %d", i1, i2);
                // 进行运算
                if (postfix.data[i].val == '+') 
                    i1 += i2; 
                else if (postfix.data[i].val == '-') 
                    i1 -= i2; 
                else if (postfix.data[i].val == 'x') 
                    i1 *= i2; 
                else if (postfix.data[i].val == '/') 
                    i1 /= i2;    
                //printf("result: %d", i1);  
                Push(S_i, i1); // 运算结果进栈
            }
        }
        int ans;
        Pop(S_i, ans);
        if (ans == 24)
            printf("Yes\n");
        else 
            printf("No\n");
    }

    return 0;
}



