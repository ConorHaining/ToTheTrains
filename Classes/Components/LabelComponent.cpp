//
// Created by conor on 03/04/18.
//

#include "LabelComponent.h"

void LabelComponent::createLabel(std::string text) {
    label = Label::createWithTTF(text, "PressStart2P.ttf", 16);
}

Label *LabelComponent::getLabel() {
    return this->label;
}
