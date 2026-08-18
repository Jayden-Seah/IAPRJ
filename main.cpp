#include <iostream>

//Start program

int main() {
	//Code starts here

	//Array used -> Layout built from top to bottom
	//Top of the layout to bottom
	std::string topDown[11] = {
		"|                              |             |",
		"|                              |    Stats:   |",
		"|                              |             |",
		"|                              |             |",
		"|                              |             |",
		"|                              |             |",
		"|                              |             |",
		"|                              |             |",
		"|                              |             |",
		"|                              |             |",
		"|                              |             |",

			
	};
	//At the textbox level down
	std::string midDown[3] = {
		"|                              |             |",
		"|         TEXTBOX              |             |",
		"|                              |             |",
	};

	std::cout << "______________________________________________" << std::endl;
	for (int i = 0; i < 11;i++) {//Top to textbox level
		std::cout << topDown[i] << std::endl;
	}
	std::cout << "|______________________________|             |" << std::endl;
	for (int i = 0;i < 3;i++) {
		std::cout << midDown[i] << std::endl;
	}
	std::cout << "|______________________________|_____________|" << std::endl;
}