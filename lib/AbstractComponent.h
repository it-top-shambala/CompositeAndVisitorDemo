#pragma once

#include <string>
#include <vector>

#include "AbstractExporter.h"

using namespace std;

class AbstractComponent {
protected:
    string _name;
    string _body;
    vector<AbstractComponent*>* _components;

    AbstractComponent(string name, string body) : _name(name), _body(body) {
        _components = new vector<AbstractComponent*>();
    }

public:
    virtual void Export(AbstractExporter* visitor) = 0;

    void AddChild(AbstractComponent* component) {
        _components->push_back(component);
    }

    vector<AbstractComponent*> GetChildren() {
        return *_components;
    }

    string GetName() {
        return _name;
    }

    string GetBody() {
        return _body;
    }
};
