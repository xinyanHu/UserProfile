//
//  UserProfile.hpp
//  test 3.24
//
//  Created by 胡欣妍 on 2018/3/28.
//  Copyright © 2018年 胡欣妍. All rights reserved.
//

#ifndef UserProfile_hpp
#define UserProfile_hpp

#include <iostream>
#include <string>
#include <map>

typedef std::string string;
enum uLevel {Beginer, Intermediate, Advanced, Guru};

class UserProfile {
    string login;
    string userName;
    int timesLogged;
    int guesses;
    int correctGuesses;
    uLevel userLevel;
    
    static std::map<string, uLevel> levelMap;
    static void init_level_map();
    static string guest_login();
    
public:
    UserProfile(string, uLevel = uLevel::Beginer);
    UserProfile();
    
    bool operator== (const UserProfile&) const;
    bool operator!= (const UserProfile&) const;
    
    string get_login() const {return login;}
    string get_user_name() const {return userName;}
    int get_login_count() const {return timesLogged;}
    int get_guess_count() const {return guesses;}
    int get_guess_correct() const {return correctGuesses;}
    
    double guess_averange() const;
    string level() const;
    
    void set_login(const string& val) {login = val;}
    void set_user_name(const string& val) {userName = val;}
    void set_login_count(int val) {timesLogged = val;}
    void set_guess_count(int val) {guesses = val;}
    void set_guess_correct(int val) {correctGuesses = val;}
    void set_level(uLevel level) {userLevel = level;}
    
    void set_level(const string& level);
    
    void add_login_count(int val = 1) {timesLogged += val;}
    void add_guess_count(int val = 1) {guesses += val;}
    void add_guess_correct(int val = 1) {guesses += val;}
    
    friend std::ostream& operator<< (std::ostream&, const UserProfile&);
};

inline double UserProfile::guess_averange() const {
    return guesses ? double(correctGuesses) / guesses : 0;
}

inline UserProfile::UserProfile(string _login, uLevel _level) : login(_login), userLevel(_level), timesLogged(1), guesses(0), correctGuesses(0) {}

inline UserProfile::UserProfile() : login("guest"), userLevel(uLevel::Beginer), timesLogged(1), guesses(0), correctGuesses(0) {
    static int id = 0;
    id++;
    login += std::to_string(id);
}

inline bool UserProfile::operator== (const UserProfile& rhs) const {
    return login == rhs.login && userName == rhs.userName;
}

inline bool UserProfile::operator!= (const UserProfile& rhs) const {
    return !(*this == rhs);
}

inline string UserProfile::level() const {
    static string level_table[] = {"Beginer", "Intermediate", "Advanced", "Guru"};
    return level_table[userLevel];
}
#endif /* UserProfile_hpp */
