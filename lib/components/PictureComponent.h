#pragma once

#include "../AbstractComponent.h"

class PictureComponent : public AbstractComponent {
private:
    string _path;

public:
    PictureComponent(string name, string body, string path) : AbstractComponent(name, body),
                                                                                   _path(path) {}

    void Export(AbstractExporter *visitor) override {
        visitor->ExportPictureComponent(this);
    }

    string GetPath() {
        return _path;
    }
};

