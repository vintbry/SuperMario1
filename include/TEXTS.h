//
// Created by Vincentius Bryant on 2024/4/18.
//

#ifndef SUPERMARIO1_TEXTS_HPP
#define SUPERMARIO1_TEXTS_HPP

#include <string>

#include "Util/GameObject.hpp"
#include "Util/Text.hpp"
#include "Util/Color.hpp"
#include "Util/Time.hpp"

class TEXTS : public Util::GameObject {
public:
    /* TEXTS() : GameObject(

             std::make_unique<Util::Text>(GA_RESOURCE_DIR"/Font/Inkfree.ttf", 20,
                                          append_string_views(s_PhaseTasks[0], s_Validation),
                                          Util::Color::FromName(Util::Colors::WHITE)),
             100) {
         m_Transform.translation = {0.0F, -270.F};
              *//*
            std::make_unique<Util::Text>(GA_RESOURCE_DIR"/Font/SuperMarioBrosNes.ttf",23,
                                         append_string_views(s_Score, s_Coins),Util::Color::FromName(Util::Colors::WHITE)),
        100) {
        m_Transform.translation = {0.0F, 220.F};
    }*/
    explicit TEXTS(const std::string& text);

    TEXTS(const TEXTS&) = delete;

    TEXTS(TEXTS&&) = delete;

    TEXTS& operator=(const TEXTS&) = delete;

    TEXTS& operator=(TEXTS&&) = delete;
/*
    void NextPhase(const int phase) {
        auto temp = std::dynamic_pointer_cast<Util::Text>(m_Drawable);
        temp->SetText(append_string_views(s_PhaseTasks[phase], s_Validation));
    }
*/
    void SetPosition(const glm::vec2& Position) { m_Transform.translation = Position; }

    void SetText(const std::string& text);






private:
    void ResetPosition() { m_Transform.translation = {0, 0}; }

    std::string m_text;

    /*
private:
    inline static std::string append_string_views(std::string_view sv1, std::string_view sv2) {
        return std::string(sv1) + "\n" + std::string(sv2);
    }

    static constexpr std::string_view s_PhaseTasks[2] = {"1-1", "1-2"};
    static constexpr std::string_view s_Validation = "Press Enter to validate";
  //  static constexpr std::string_view s_TITLE ="SCORE                   COINS                   WORLD                 TIME";
  //  static constexpr std::string_view s_score = "       0      ";
    static constexpr std::string_view s_Score = "SCORE \n 0";
    static constexpr std::string_view s_Coins = "COINS \n 0";
*/
};


#endif //SUPERMARIO1_TEXTS_HPP

