# Общие настройки компилятора
CXX = g++
CXXFLAGS = -std=c++11 -Wall
BUILD_DIR = build

# Цель для компиляции лабораторной работы
gen:
ifeq ($(LAB), 13)
	$(CXX) $(CXXFLAGS) lab$(LAB).cpp libs/matrix_operations.cpp libs/array_operations.cpp -o $(BUILD_DIR)/lab$(LAB)
else ifeq ($(LAB), 15)
#тредуется установка
#sudo apt-get install libsdl2-dev libsdl2-ttf-dev
	$(CXX) $(CXXFLAGS) lab$(LAB).cpp -o $(BUILD_DIR)/lab$(LAB) -lSDL2 -lSDL2_ttf
else
	$(CXX) $(CXXFLAGS) lab$(LAB).cpp -o $(BUILD_DIR)/lab$(LAB)
endif

run: gen
	./$(BUILD_DIR)/lab$(LAB)

# Очистка сгенерированных файлов
clean:
	rm -rf $(BUILD_DIR)/*