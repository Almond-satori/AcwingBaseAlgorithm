#include <iostream>
#include <unordered_map>

using namespace std;

const int N = 100010;
char op[N];
int num[N],num_top = 0,op_top = 0;

void calc()
{
    int x;
    int b = num[num_top--];
    int a = num[num_top--];
    char oper = op[op_top--];
    if(oper == '+'){
        x = a + b;
    }else if(oper == '-'){
        x = a - b;
    }else if(oper == '*'){
        x = a * b;
    }else if(oper == '/'){
        x = a / b;
    }
    num[++num_top] = x;
}

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    // 定义一个运算符优先级
    unordered_map<char,int> pr = {{'+',1},{'-',1},{'*',2},{'/',2}};
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); ++i){
        char ch = s[i];
        if(isdigit(ch)){
            // 数字可能不止一位
            int x = 0;
            int j = i;
            while(j < s.size() && isdigit(s[j])) x = 10 * x + s[j++] - '0';
            num[++num_top] = x;
            i = j - 1; // i在外层for会自增
        }else{
            // 读取操作符
            if(ch == '(') op[++op_top] = '(';
            else if(ch == ')') {
                while(op_top && op[op_top] != '(') calc();
                --op_top; // 将(也弹出
            }else{
                // ch是运算符号,根据优先级计算
                // 先进入栈的运算符,在顺序这个维度上优先级高于后入栈的运算符
                // 如果该运算符本身的优先级还大于等于当前处理的运算符,则一定先处理
                while(op_top && pr[op[op_top]] >= pr[ch]){
                    calc();
                }
                op[++op_top] = ch;
            }
        }
    }
    while(op_top){
        calc();
    }
    printf("%d ",num[num_top]);
    return 0;
}