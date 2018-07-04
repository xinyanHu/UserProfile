//
//  main.cpp
//  test 3.24
//
//  Created by 胡欣妍 on 2018/3/24.
//  Copyright © 2018年 胡欣妍. All rights reserved.
//

#include <iostream>
#include "UserProfile.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    UserProfile anon;
    cout << anon << endl;
    
    UserProfile _anon;
    cout << _anon << endl;
    
    UserProfile a("a", uLevel::Guru);
    cout << a << endl;
    return 0;
}
