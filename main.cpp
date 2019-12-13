#include <iostream>
using namespace std;

#define OK 1 // OK��ERROR��ʾִ��ĳЩ����ĳɹ����
#define ERROR 0
#define TRUE 1 // TRUE��FALSE��ʾĳЩ����ִ���жϽ���ķ������
#define FALSE 0
//using ElemType = int;
using ElemType = char;
using Status = int; // Status�Ǻ��������ͣ���ֵ�Ǻ������״̬���룬��OK��ERROR
#define MAXSIZE 20
struct SqStack{
    ElemType data[MAXSIZE];
    int top;
};

Status InitStack(SqStack &S) 
{   
    S.top = -1; // ջ��Ԫ��ָ��ջ����ϵ�Ԫ�أ���ջʱtop=-1
    return OK;
}

Status StackEmpty(SqStack S) 
{
    if (S.top == -1) 
        return TRUE;
    else 
        return FALSE;
}

// ��ʼ������˳��ջL�Ѵ��ڣ�1<=i<=StackLength(L)
// �������������Ԫ��eΪ�µ�ջ��Ԫ��
Status Push(SqStack &S, ElemType e)
{
    if (S.top == MAXSIZE - 1)
        return ERROR;
    ++S.top;
    S.data[S.top] = e;

    return OK;
}

// ��ʼ������˳��ջL�Ѵ��ڣ�1<=i<=StackLength(L)
// ���������ɾ��ջS��ջ��Ԫ�أ�����e������ֵ��
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

// ******************����Ĵ���������һģһ������˳��ջ��Ψһ���������data������һ����charһ����int����Ϊ�Ҳ�֪����ôֱ���޸�data�����ͣ����������������صĲ���������ֻ��������һ�� **********
struct SqStack_int{
    int data[MAXSIZE];
    int top;
};

Status InitStack(SqStack_int &S) 
{   
    S.top = -1; // ջ��Ԫ��ָ��ջ����ϵ�Ԫ�أ���ջʱtop=-1
    return OK;
}

Status StackEmpty(SqStack_int S) 
{
    if (S.top == -1) 
        return TRUE;
    else 
        return FALSE;
}

// ��ʼ������˳��ջL�Ѵ��ڣ�1<=i<=StackLength(L)
// �������������Ԫ��eΪ�µ�ջ��Ԫ��
Status Push(SqStack_int &S, int e)
{
    if (S.top == MAXSIZE - 1)
        return ERROR;
    ++S.top;
    S.data[S.top] = e;

    return OK;
}

// ��ʼ������˳��ջL�Ѵ��ڣ�1<=i<=StackLength(L)
// ���������ɾ��ջS��ջ��Ԫ�أ�����e������ֵ��
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
// ***************** SqStack_int�Ĵ������ *************

struct element{
    char t; // type��'c'��ʾ���ţ�'i'��ʾ����
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

int prior(char c) // ������ʱ����ܻ���int��char��ǿ��ת���������������
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
            //��ȡ���룬����Ϊ��׺���ʽ
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
         
        // ����׺���ʽΪ��׺���ʽ����׺���ʽ�в��������ţ�
        // ���򣺴����ұ�����׺���ʽ��ÿ�����ֺͷ���
        // �������֣���������׺���ʽ��
        // ���������ţ���ջ��Ԫ�����γ�ջ�������ֱ��ջ�ڵ�һ�������ų�ջ��
        // ���������ţ���ֱ�ӽ�ջ��
        // ��������������ţ���������ȼ�����ջ�����ţ��˳������ڼӼ�������ֱ�ӽ�ջ��
            // ��������ȼ�������ջ�����ţ��򲻶Ͻ�ջ��Ԫ�ص����������׺���ʽ��ֱ���������ȼ��ȵ�ǰ���Ż�Ҫ�͵ķ���ʱֹͣ�������Ǹ����ȼ����͵ķ��Ų���������Ȼ�󽫵�ǰ���Ž�ջ����������ֻ���������㣬���ȼ�����ջ�����ŵ����ֻ�ᷢ����+-����*/������û�б�+-���ȼ����͵ķ��ţ������������൱�ڻ��ջ��Ԫ��ȫ�������
        // �������һֱ����׺���ʽ������������ջ��Ԫ�ص����������׺���ʽ���õ����յĺ�׺���ʽ��
        
        SqStack S;
        InitStack(S);
        expression postfix;
        ElemType e;
        for (int i = 0; i != midfix.length; ++i) {
            if (midfix.data[i].t == 'i') { // ����
                add(postfix, 'i', midfix.data[i].val);
            }
            else if (midfix.data[i].val == ')') { // ������
                // ջ��Ԫ�����γ�ջ�������ֱ��ջ�ڵ�һ�������ų�ջ��                
                Pop(S, e);
                while (e != '(') {
                    add(postfix, 'c', e);
                    Pop(S, e);
                }
            }
            else if (midfix.data[i].val == '(') { // ������
                Push(S, midfix.data[i].val); 
            }
            else { // �����������
                if (StackLength(S) == 0) { // ջΪ�վ�ֱ�Ӳ����ˣ�ûɶ�ñȽϵ�
                    Push(S, midfix.data[i].val);
                    continue;
                }
                GetTop(S, e);
                if (prior(midfix.data[i].val) <= prior(e)) { // ����������Ż�������
                    // ���Ͻ�ջ��Ԫ�ص�����ֱ���������ȼ��ȵ�ǰ���Ż�Ҫ�͵ķ���ʱֹͣ�������Ǹ����ȼ����͵ķ��Ų�������        
                    while (1) {
                        if ( prior(midfix.data[i].val) > prior(e) || e == '(' || StackLength(S) == 0) // ֻ�Ǿ��ü���whileѭ�����ж�������������⣬���Զ���ȡ�����������Ϊbreak������
                            break;
                        Pop(S, e);
                        add(postfix, 'c', e);
                        GetTop(S, e);
                    }
                    Push(S, midfix.data[i].val);
                } else // ���ȼ�����ջ������
                    Push(S, midfix.data[i].val);  
            }
        }
        while (StackLength(S) != 0) { // ��׺���ʽ������������ջ��Ԫ�ص����������׺���ʽ
            Pop(S, e);
            add(postfix, 'c', e);
        }
      //  printf("postfix.length: %d \n", postfix.length);
        
        // �����׺���ʽ��ֵ
        // ���򣺴����ұ������ʽ��ÿ�����ֺͷ��ţ����������־ͽ�ջ�������Ƿ��ţ��ͽ�����ջ�����������ֳ�ջ���������㣬��������ջ��һֱ�����ջ�ý����
        SqStack_int S_i;
        InitStack(S_i);    
        int i1, i2;
        for (int i = 0; i != postfix.length; ++i) {
            if (postfix.data[i].t == 'i') // ����ֱ�ӽ�ջ
                Push(S_i, postfix.data[i].val);
            else { // ���ţ�������ջ�����������ֳ�ջ
                Pop(S_i, i2);
                Pop(S_i, i1);
                //printf("i1: %d, i2: %d", i1, i2);
                // ��������
                if (postfix.data[i].val == '+') 
                    i1 += i2; 
                else if (postfix.data[i].val == '-') 
                    i1 -= i2; 
                else if (postfix.data[i].val == 'x') 
                    i1 *= i2; 
                else if (postfix.data[i].val == '/') 
                    i1 /= i2;    
                //printf("result: %d", i1);  
                Push(S_i, i1); // ��������ջ
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



