#pragma once

#include "../AbstractComponent.h"

class TextComponent : public AbstractComponent {
public:
    TextComponent(string name, string body) : AbstractComponent(name, body) {}

    void Export(AbstractExporter* visitor) override {
        visitor->ExportTextComponent(this);
    }
};

