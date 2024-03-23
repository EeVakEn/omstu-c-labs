/*
4. Создать класс «меню» и его наследников - горизонтальное, вертикальное, иерархическое (добавить пункт, нарисовать).
*/

// make run LAB=3
#include <iostream>
#include <vector>
#include <windows.h>

class Menu {
protected:
    std::vector<std::string> items;
    int selectedItem;

public:
    Menu() : selectedItem(0) {}

    void addItem(const std::string& item) {
        items.push_back(item);
    }

    virtual void draw() const = 0;

    void selectNext() {
        selectedItem = (selectedItem + 1) % items.size();
    }

    void selectPrevious() {
        selectedItem = (selectedItem - 1 + items.size()) % items.size();
    }

    std::string getSelectedItem() const {
        return items[selectedItem];
    }
};

class HorizontalMenu : public Menu {
public:
    void draw() const override {
        for (int i = 0; i < items.size(); ++i) {
            if (i == selectedItem) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                std::cout << items[i] << " ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            } else {
                std::cout << items[i] << " ";
            }
        }
        std::cout << std::endl;
    }
};

class VerticalMenu : public Menu {
public:
    void draw() const override {
        for (int i = 0; i < items.size(); ++i) {
            if (i == selectedItem) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                std::cout << items[i] << std::endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            } else {
                std::cout << items[i] << std::endl;
            }
        }
    }
};

class HierarchicalMenu : public Menu {
private:
    std::vector<Menu*> subMenus;

public:
    void addSubMenu(Menu* menu) {
        subMenus.push_back(menu);
    }

    void draw() const override {
        for (int i = 0; i < items.size(); ++i) {
            if (i == selectedItem) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                std::cout << items[i] << std::endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                if (i < subMenus.size()) {
                    subMenus[i]->draw();
                }
            } else {
                std::cout << items[i] << std::endl;
            }
        }
    }
};

int main() {
    HorizontalMenu hMenu;
    hMenu.addItem("File");
    hMenu.addItem("Edit");
    hMenu.addItem("View");

    VerticalMenu vMenu;
    vMenu.addItem("New");
    vMenu.addItem("Open");
    vMenu.addItem("Save");

    HierarchicalMenu hiMenu;
    hiMenu.addItem("File");
    hiMenu.addItem("Edit");

    HorizontalMenu fileMenu;
    fileMenu.addItem("New");
    fileMenu.addItem("Open");
    fileMenu.addItem("Save");
    hiMenu.addSubMenu(&fileMenu);

    hMenu.draw();
    vMenu.draw();
    hiMenu.draw();

    return 0;
}
