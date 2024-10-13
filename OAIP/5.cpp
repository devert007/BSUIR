#include <iostream>
#include <stack>
#include <string>
#include <cctype>

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    else if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

std::string infixToPostfix(const std::string& infix) {
    std::string postfix;
    std::stack<char> operators;

    for (char c : infix) {//идем  по каждому элементу
        if (std::isalnum(c)) {//если наш символ это число
            postfix += c;//добавляем его в резалт
        }
        else if (c == '(') {//но если открывающая скобка
            operators.push(c);//пушим его в наш стэк операндов
        }
        else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {//до тех пор пока не пуст стэк и верхний не равен (
                postfix += operators.top();//добавляем к результирующей
                operators.pop();//удаляем первую строку
            }
            operators.pop(); //и еще раз удаляем первую строку
        }
        else if (isOperator(c)) {//если это оператор
            while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {//пока наш стек не пуст и приоритет верхнего не меньше  текущего приоритета item
                postfix += operators.top();//добавляем его в резалт
                operators.pop();//и удаляем из стека
            }
            operators.push(c);//пушим текущий элемент
        }
    }

    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}
int evaluatePostfix(const std::string& postfix) {
    std::stack<int> operands;

    for (char c : postfix) {
        if (std::isalnum(c)) {
            operands.push(c - '0');
        }
        else if (isOperator(c)) {
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();
            int result;
            switch (c) {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
            }
            operands.push(result);
        }
    }

    return operands.top();
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::string infixExpression = "a-(b/c*(d+e))";
    std::string postfixExpression = infixToPostfix(infixExpression);
    std::cout << "Ваше выражение " << infixExpression << '\n';
    std::cout << "Обратная польская запись " << postfixExpression << '\n';
   // std::cout << "Ваше значение обратной польской записи: " << evaluatePostfix(infixExpression) << '\n';
    return 0;
}
