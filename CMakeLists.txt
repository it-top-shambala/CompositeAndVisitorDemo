cmake_minimum_required(VERSION 3.25)
project(VisitorAndComposite)

set(CMAKE_CXX_STANDARD 17)

add_executable(VisitorAndComposite main.cpp lib/AbstractComponent.h lib/AbstractExporter.h lib/components/TextComponent.h lib/components/PictureComponent.h lib/exporters/ExporterToXml.h lib/exporters/ExporterToTxt.h)
