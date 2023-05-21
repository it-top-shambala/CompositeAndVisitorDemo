#pragma once

#include <fstream>
#include <string>

#include "../AbstractExporter.h"

using namespace std;

class ExporterToXml : public AbstractExporter {
private:
    string _pathXml;

    void WriteToFile(string msg) {
        ofstream file;
        file.open(_pathXml, ios::app);
        file << msg << endl;
        file.close();
    }

    string CreateOpenTag(string tag, string nameAttribute = "", string attribute = "") {
        if (nameAttribute == "") {
            return "<" + tag + ">";
        } else {
            return "<" + tag + " " + nameAttribute + "=" + "'" + attribute + "'" + ">";
        }

    }
    string CreateCloseTag(string tag) {
        return "</" + tag + ">";
    }
public:
    ExporterToXml(string pathXml) : _pathXml(pathXml) {}

    void ExportTextComponent(TextComponent *component) override {
        string openTag = CreateOpenTag(component->GetName());
        string closeTag = CreateCloseTag(component->GetName());
        string line = openTag + component->GetBody() + closeTag;
        WriteToFile(line);
    }

    void ExportPictureComponent(PictureComponent *component) override {
        string openTag = CreateOpenTag(component->GetName(), "description", component->GetBody());
        string closeTag = CreateCloseTag(component->GetName());
        string line = openTag + component->GetPath() + closeTag;
        WriteToFile(line);
    }
};

