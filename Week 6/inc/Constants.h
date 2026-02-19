#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

namespace Constants {
    const std::string WHITESPACES = " \t\n";
    const std::string EMPTY = "";
    const std::string NEWLINE = "\n";
    const std::string INVALID_FILENAME_CHARS = "/:*?\"<>|\\";
    const std::string FIELDS[] = {"Name", "Age", "Gender", "City"};
    const int NUM_FIELDS = 4;
    const char VALID_GENDERS[] = {'M', 'F'};
    const int NUM_GENDERS = 2;
    const int MIN_AGE = 0;
    const int MAX_AGE = 120;
    const std::string JSON_KEY = "records";
    const std::string COMMA = ",";
    const std::string XML_ROOT = "records";
    const std::string XML_RECORD = "person";
}

namespace Menu {
    const std::string MAIN = "\n=== File Parser ===\n1. Create New File\n2. Edit File\n3. Parse & Display\n4. Delete File\n5. Exit\nEnter choice: ";
    const std::string SELECT_FORMAT = "\nSelect Format:\n1. JSON\n2. CSV\n3. XML\nEnter choice: ";
    const std::string EDIT = "\n=== Edit Menu ===\n1. Add Record\n2. Update Record\n3. Delete Record\n4. Save & Exit\n5. Cancel\nEnter choice: ";
}

namespace Prompt {
    const std::string ENTER_FILENAME = "Enter filename (without extension): ";
    const std::string ENTER_NUM_RECORDS = "Enter number of records: ";
    const std::string ENTER_NAME = "Enter name: ";
    const std::string ENTER_AGE = "Enter age ";
    const std::string ENTER_GENDER = "Enter gender:  ";
    const std::string ENTER_CITY = "Enter your city: ";
    const std::string SELECT_FILE = "\nSelect file number: ";
    const std::string SELECT_RECORD = "Select record number: ";
}

namespace Success {
    const std::string FILE_CREATED = "File created successfully!\n";
    const std::string FILE_SAVED = "File saved successfully!\n";
    const std::string FILE_PARSED = "File parsed successfully!\n";
    const std::string FILE_DELETED = "File deleted successfully!\n";
    const std::string RECORD_ADDED = "Record added successfully!\n";
    const std::string RECORD_UPDATED = "Record updated successfully!\n";
    const std::string RECORD_DELETED = "Record deleted successfully!\n";
}

namespace Error {
    const std::string FILE_NOT_FOUND = "File not found!\n";
    const std::string INVALID_FORMAT = "Invalid file format!\n";
    const std::string PARSE_FAILED = "Failed to parse file!\n";
    const std::string EMPTY_FILE = "File is empty or invalid!\n";
    const std::string NO_FILES = "No files found in data directory!\n";
    const std::string INVALID_CHOICE = "Invalid choice!\n";
    const std::string INVALID_INPUT = "Invalid input. Please try again!\n";
    const std::string INVALID_INDEX = "Invalid index!\n";
    const std::string INVALID_AGE = "Invalid age!\n";
    const std::string INVALID_GENDER = "Invalid gender! Please enter M/F.\n";
    const std::string FILE_OPEN_FAILED = "Could not open file!\n";
    const std::string FILE_WRITE_FAILED = "Could not write to file!\n";
    const std::string DIRECTORY_NOT_FOUND = "Data directory not found!\n";
}

namespace Info {
    const std::string SEPARATOR = "========================================\n";
    const std::string PARSED_DATA_HEADER = "Parsed Data from: ";
    const std::string TOTAL_RECORDS = "Total Records: ";
    const std::string CURRENT_DATA = "\n=== Current Data ===\n";
    const std::string AVAILABLE_FILES = "\n=== Available Files ===\n";
    const std::string NO_RECORDS = "No records to display.\n";
    const std::string RECORD_PREFIX = "Record ";
    const std::string NAME = "  Name: ";
    const std::string AGE = "  Age: ";
    const std::string GENDER = "  Gender: ";
    const std::string CITY = "  City: ";
}

namespace Path {
    const std::string DATA_DIR = "data/";
}

namespace Extensions {
    const std::string JSON = ".json";
    const std::string CSV = ".csv";
    const std::string XML = ".xml";
}

#endif
