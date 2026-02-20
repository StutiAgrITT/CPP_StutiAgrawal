#include "XMLParser.h"
#include "Constants.h"
#include "Utility.h"
#include "Exceptions.h"
#include <tinyxml2.h>

XMLParser::XMLParser() = default;
XMLParser::~XMLParser() = default;

void XMLParser::parse(const std::string& filePath) {
    tinyxml2::XMLDocument document;

    if (document.LoadFile(filePath.c_str()) != tinyxml2::XML_SUCCESS) {
        throw FileException(Error::FILE_OPEN_FAILED);
    }

    tinyxml2::XMLElement* root = document.FirstChildElement(Constants::XML_ROOT.c_str());

    if (!root) {
        throw ParseException(Error::PARSE_FAILED);
    }

    clearRecords();

    tinyxml2::XMLElement* recordElement = root->FirstChildElement(Constants::XML_RECORD.c_str());

    while (recordElement) {
        std::map<std::string, std::string> record;

        for (int fieldIndex = 0; fieldIndex < Constants::NUM_FIELDS; ++fieldIndex) {
            tinyxml2::XMLElement* field = recordElement->FirstChildElement(Constants::FIELDS[fieldIndex].c_str());
            record[Constants::FIELDS[fieldIndex].c_str()] = field->GetText();
        }
        _records.push_back(record);

        recordElement = recordElement->NextSiblingElement(Constants::XML_RECORD.c_str());
    }
}

void XMLParser::save(const std::string& filePath) {
    tinyxml2::XMLDocument document;

    tinyxml2::XMLElement* root = document.NewElement(Constants::XML_ROOT.c_str());

    document.InsertFirstChild(root);

    for (std::map<std::string, std::string> record : _records) {
        tinyxml2::XMLElement* recordElement = document.NewElement(Constants::XML_RECORD.c_str());

        for (int fieldIndex = 0; fieldIndex < Constants::NUM_FIELDS; fieldIndex++) {
            tinyxml2::XMLElement* field = document.NewElement(Constants::FIELDS[fieldIndex].c_str());
            field->SetText(record.at(Constants::FIELDS[fieldIndex]).c_str());
            recordElement->InsertEndChild(field);
        }
        root->InsertEndChild(recordElement);
    }

    if (document.SaveFile(filePath.c_str()) != tinyxml2::XML_SUCCESS) {
        throw FileException(Error::FILE_WRITE_FAILED);
    }
}
