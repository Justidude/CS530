/*
 * Artur Prusinowski, Anas Khafagi, Justin Waymire
 * Edoras account: cssc0631
 * Assignment 2
 *
  macroPP.h
  CS530, Fall 2016
*/

#ifndef MACROPP_H
#define MACROPP_H
#include <string>
#include <vector>
#include <iostream>     // std::cout
#include <fstream>      // std::ifstream
#include <cstddef>      //size_t
#include "file_parser.h"
#include "macroPP_error_exception.h"

using namespace std;

typedef vector<script> macros;

class macroPP {
public:
    /**
    * Reads file in and parses it removing macros and storing them.
    * @param filename - string containing the name of the source file to be processed
    * @return - file_parser object
    */
    macroPP(string);

    /**
     * Destructor
     * */
    ~macroPP(){};

    /**
    * processes the source file, storing the code in the
    * all_rows_vect data structure and macros in the macros data structure.
    * Throws a macroPP_error_exception if an error occurs.
    */
    void process_file();

	/**
	* prints the macros to stdout.
    */
    void print_macros();

    /**
	* prints the macros to stdout.
    */
    void print_file();

private:

    /** Source file file name*/
    string filename;

	/** File parser to extract macros **/
	file_parser* file_processor;

	/** The current row under analysis **/
	row_vect current_row;

	/** Script with macros removed **/
	script script_final;

	/** Current macro **/
	script current_macro;

	/** Vector of macros removed from file*/
	macros file_macros;

};
#endif


