#include "./lib/components/TextComponent.h"
#include "./lib/components/PictureComponent.h"

#include "./lib/exporters/ExporterToXml.h"
#include "./lib/exporters/ExporterToTxt.h"

using namespace std;

void Export(AbstractComponent* component, AbstractExporter* exporter);

int main() {
    auto* component_1 = new TextComponent("root", "root");
    auto* component_2 = new TextComponent("element1", "Element 1");
    auto* component_3 = new TextComponent("element2", "Element 2");
    auto* component_4 = new TextComponent("element3", "Element 3");
    auto* component_5 = new PictureComponent("picture1", "Picture 1", "path");

    component_3->AddChild(component_4);
    component_2->AddChild(component_3);
    component_1->AddChild(component_2);
    component_1->AddChild(component_5);

    AbstractExporter* exporterToXml = new ExporterToXml("D:\\Programming\\VisitorAndComposite\\components.xml");
    AbstractExporter* exporterToTxt = new ExporterToTxt("D:\\Programming\\VisitorAndComposite\\components.txt");

    Export(component_1, exporterToXml);
    Export(component_1, exporterToTxt);

    return 0;
}

void Export(AbstractComponent* component, AbstractExporter* exporter) {
    component->Export(exporter);
    for (auto child : component->GetChildren()) {
        Export(child, exporter);
        if (child->GetChildren().empty()) continue;
    }
}
