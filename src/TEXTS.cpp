//
// Created by Vincentius Bryant on 2024/4/25.
//

#include "TEXTS.h"
#include "Character.h"
#include "Util/Image.hpp"
#include "Util/Time.hpp"

TEXTS::TEXTS(const std::string& text) {
    SetText(text);

    ResetPosition();
}

void TEXTS::SetText(const std::string &text) {
    m_text = text;

    m_Drawable = std::make_shared<Util::Text>(GA_RESOURCE_DIR"/Font/SuperMarioBrosNes.ttf", 23,
                                              m_text, Util::Color::FromName(Util::Colors::WHITE));

}
