#pragma once

#include <fstream>
#include <string>

#include "../AbstractExporter.h"

using namespace std;

class ExporterToTxt : public AbstractExporter {
private:
    string _pathFile;

    void WriteToFile(string msg) {
        ofstream file;
        file.open(_pathFile, ios::app);
        file << msg << endl;
        file.close();
    }

public:
    ExporterToTxt(string pathFile) : _pathFile(pathFile) {}

    void ExportTextComponent(TextComponent *component) override {
        WriteToFile(component->GetName() + ";" + component->GetBody());
    }

    void ExportPictureComponent(PictureComponent *component) override {
        WriteToFile(component->GetName() + ";" + component->GetBody() + ";" + component->GetPath());
    }
};