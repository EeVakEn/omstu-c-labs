/*
4. Создать класс «меню» и его наследников - горизонтальное, вертикальное, иерархическое (добавить пункт, нарисовать).
*/

// make run LAB=3
#include <iostream>
#include <vector>

class Menu {
protected:
    std::vector<std::string> items;

public:
    void addItem(const std::string& item) {
        items.push_back(item);
    }

    virtual void draw(int depth = 0) const = 0;
};

class HorizontalMenu : public Menu {
public:
    void draw(int depth = 0) const override {
        for (int i = 0; i < depth; ++i) {
            std::cout << "---";  // отступ для каждого уровня глубины
        }
        for (const auto& item : items) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
};

class VerticalMenu : public Menu {
public:
    void draw(int depth = 0) const override {
        for (const auto& item : items) {
            for (int i = 0; i < depth; ++i) {
                std::cout << "---";  // отступ для каждого уровня глубины
            }
            std::cout << item << std::endl;
        }
    }
};

class HierarchicalMenu : public Menu {
private:
    struct MenuItem {
        std::string title;
        Menu* submenu;

        MenuItem(const std::string& t, Menu* s = nullptr) : title(t), submenu(s) {}
    };

    std::vector<MenuItem> items;

public:
    void addItem(const std::string& title, Menu* submenu = nullptr) {
        items.emplace_back(title, submenu);
    }

    void draw(int depth = 0) const override {
        for (const auto& item : items) {
            for (int i = 0; i < depth; ++i) {
                std::cout << "---";  // отступ для каждого уровня глубины
            }
            std::cout << item.title << std::endl;

            if (item.submenu) {
                item.submenu->draw(depth + 1);  // рекурсивный вызов для подменю
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
    hiMenu.addItem("File", &hMenu);// добавляем подменю в горизонтальное меню
    hiMenu.addItem("Edit");

    HorizontalMenu hSubMenu;
    hSubMenu.addItem("Import");
    hSubMenu.addItem("Export");
    hiMenu.addItem("File Operations", &hSubMenu);  // добавляем подменю в вертикальное меню
    hiMenu.addItem("View", &vMenu);
    
    // Копируем предварительно или создаем новое меню иначе все зациклится если передадим ссылку на текущее hiMenu
    HierarchicalMenu hiMenu2 = hiMenu; 
    hiMenu.addItem("Hierahical menu in hierahical menu", &hiMenu2);

    // hMenu.draw();
    // vMenu.draw();
    hiMenu.draw();

    return 0;
}