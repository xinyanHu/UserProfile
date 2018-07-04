//
//  UserProfile.cpp
//  test 3.24
//
//  Created by 胡欣妍 on 2018/3/28.
//  Copyright © 2018年 胡欣妍. All rights reserved.
//

#include "UserProfile.hpp"

// enum uLevel {Beginer, Intermediate, Advanced, Guru};
std::map<string, uLevel> UserProfile::levelMap;

void UserProfile::init_level_map() {
    levelMap["Beginer"] = uLevel::Beginer;
    levelMap["Intermediate"] = uLevel::Intermediate;
    levelMap["Advanced"] = uLevel::Advanced;
    levelMap["Guru"] = uLevel::Guru;
}

void UserProfile::set_level(const string& level) {
    std::map<string, uLevel>::const_iterator cit;
    if (levelMap.empty()) {
        init_level_map();
    }
    userLevel = ((cit = levelMap.find(level)) != levelMap.cend()) ? cit->second : uLevel::Beginer;
}

std::ostream& operator<< (std::ostream& os, const UserProfile& rhs) {
    return os << rhs.login << "\t" << rhs.userLevel << "\t"
    << rhs.timesLogged << "\t" << rhs.guesses << "\t"
    << rhs.correctGuesses << "\t" << rhs.guess_averange();
}

