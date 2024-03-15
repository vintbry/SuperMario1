//
// Created by Felicia Rulita on 2024/3/12.
//

#ifndef SUPERMARIO1_PHASERESOURCESMANAGER_H
#define SUPERMARIO1_PHASERESOURCESMANAGER_H

#include "Util/GameObject.hpp"
#include "Character.h"
#include "BackgroundImage.h"

class PhaseResourcesManager {
public:
    PhaseResourcesManager();

    [[nodiscard]] std::vector<std::shared_ptr<Util::GameObject>> GetChildren() const {
        return {m_Background};
    }


private:
    std::shared_ptr<BackgroundImage> m_Background;

    int m_Phase = 1;
};

#endif //SUPERMARIO1_PHASERESOURCESMANAGER_H
