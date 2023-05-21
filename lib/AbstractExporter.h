#pragma once

class TextComponent;
class PictureComponent;

class AbstractExporter {
public:
    virtual void ExportTextComponent(TextComponent* component) = 0;
    virtual void ExportPictureComponent(PictureComponent* component) = 0;
};
