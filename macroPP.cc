#include <iomanip>
#include "macroPP.h"
#define CONTINUE(R) (R=='Y' || R=='y')
/**
 *
 * @param filename - string containing the name of the source file to be tokenized
 * @return - macroPP object
 */
macroPP::macroPP(string filename) {
    this->filename = filename;
	file_processor = new file_parser(filename);
}

int main(int argc, char **argv) {
	char resp;
    bool errors = false;

    if (argc != 2) {
        cout << "Put the filename as the only argument" << endl;
        return 1;
    }

    do {

        macroPP *macro_extractor = new macroPP(argv[1]);

        try {
            macro_extractor->process_file();
            macro_extractor->print_file();
			macro_extractor->print_macros();
        }
        catch (macroPP_error_exception &e) {
            errors = true;
            cout << e.getMessage() << endl;
        }
        if (!errors) {


        }
        cout << "Run Again (Y/N): ";
        cin >> resp;
        delete macro_extractor;

    } while CONTINUE(resp);
	return 0;
}

void macroPP::process_file() {
	bool errors = false;
	int size;
	try {
		file_processor->read_file();
	}
	catch (file_parse_exception &e) {
		errors = true;
		cout << e.getMessage() << endl;
	}
	if (!errors) {
		size = file_processor->size();
		// Cycle through all the lines in the script 
		for (int i = 0; i < size; i++) {
			// Take in a line to check
			current_row = file_processor->get_line(i);
			// If it is a macro then parse out the macro
			if (current_row[1].compare("macro") == 0) {
				// Clear out any old macro text from vector
				current_macro.clear();
				// Cycle through the lines of the macro, adding them to current_macro
				while (current_row[1].compare("endm") != 0) {
					// Remove the comment
					current_row[3].clear();
					// Add row to current macro
					current_macro.push_back(current_row);
					// Continue to iterate through macro
					i++;
					current_row = file_processor->get_line(i);
				}
				// Add the complete macro to the the vector of macros
				file_macros.push_back(current_macro);
			// If it is not a macro then add it to the macro-free file
			} else {
				script_final.push_back(current_row);
			}
		}
	}
}
//Print functions use the file parser's print method to output
void macroPP::print_file() {
	file_processor->print_file(script_final);
}
//Prints all macros currently on file
void macroPP::print_macros() {
	int num_macros = file_macros.size();
	for (int i = 0; i < num_macros; i++) {
		file_processor->print_file(file_macros[i]);
	}
	
}