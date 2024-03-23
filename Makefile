# Общие настройки компилятора
CXX = g++
CXXFLAGS = -std=c++11 -Wall
BUILD_DIR = build

# Цель для компиляции лабораторной работы
gen:
	$(CXX) $(CXXFLAGS) lab$(LAB).cpp -o $(BUILD_DIR)/lab$(LAB)

run: gen
	./$(BUILD_DIR)/lab$(LAB)

# Очистка сгенерированных файлов
clean:
	rm -rf $(BUILD_DIR)