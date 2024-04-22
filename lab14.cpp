/*

2. Используя динамическую структуру список, проверить, является ли он упорядоченным набором чисел.

 Реализовать задачу с использованием другой динамической структуры или придумать свою задачу, написать и отладить для нее программу. 

 Задача: 
 Написать программу на C++, которая проверяет корректность расстановки скобок в строке. 
 Строка считается корректной, если каждой открывающей скобке соответствует закрывающая скобка правильного типа (и в правильном порядке).
*/

#include <iostream>
using namespace std;
#define STACK_UNDERFLOW -101

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node(T val) 
    {
        this->data = val;
        this->next = nullptr;
    }
};

template <typename T>
class MyList{
private:
    Node<T>* head;
public:
    MyList(): head(nullptr) {}

    void append(T val) {
        if (!head) {
            head = new Node<T>(val);
            return;
        }
        
        Node<T>* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new Node<T>(val);
    }

    void print() {
        Node<T>* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    bool isOrdered() {
        if (!head) {
            return true; 
        }
        
        Node<T>* temp = head;
        while (temp->next) {
            if (temp->data > temp->next->data) {
                return false;
            }
            temp = temp->next;
        }
        return true; 
    }
};

template <typename T>
class MyStack {
private:
    Node<T>* topNode;

public:
    MyStack() : topNode(nullptr) {}

    void push(T val) {
        Node<T>* newNode = new Node<T>(val);
        newNode->next = topNode;
        topNode = newNode;
    }

    T pop() {
        if (isEmpty()) {
            exit(STACK_UNDERFLOW);
        }
        
        Node<T>* temp = topNode;
        topNode = topNode->next;
        T poppedValue = temp->data;
        delete temp;
        
        return poppedValue;
    }

    bool isEmpty() {
        return topNode == nullptr;
    }

    T top() {
        return topNode->data;
    }


};
void task1(){
    // Создаем список на основе массива
    MyList<int> myList;
    myList.append(1);
    myList.append(2);
    myList.append(3);
    myList.append(4);
    myList.append(5);


    cout << "Задание 1" << endl;
    myList.print(); 
    if (myList.isOrdered()) {
        cout << "Список упорядоченный." << endl;
    } else {
        cout << "Список не упорядоченный." << endl;
    }
}

bool isBalancedBrackets(string s) {
    MyStack<char> stack;
    for (char ch : s) {
        if (ch == '(' || ch == '[' || ch == '{') {
            stack.push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (stack.isEmpty()) {
                return false; // закрывающая скобка без соответствующей открывающей
            }
            
            char topCh = stack.top();
            stack.pop();

            if ((ch == ')' && topCh != '(') ||
                (ch == ']' && topCh != '[') ||
                (ch == '}' && topCh != '{')) {
                return false; // несоответствие типов скобок
            }
        }
    }

    return stack.isEmpty(); // стек должен быть пустым после проверки всех символов
}
void task2(){
    string str = "{[(()]}";
    cout << "Задание 2" << endl;
    cout << str << endl;
    if (isBalancedBrackets(str)) {
        cout << "Скобки раставлены верно." << endl;
    } else {
        cout << "Скобки раставлены неверно." << endl;
    }
}

int main() {
    task1();
    task2();
    return 0;
}
