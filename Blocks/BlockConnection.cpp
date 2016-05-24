//
//  BlockConnection.cpp
//  Blocks
//
//  Created by Alexander Blokhin on 20.05.16.
//  Copyright © 2016 Alexander Blokhin. All rights reserved.
//

#include "BlockConnection.hpp"
#include <string.h>

void BlockConnection::makeRequest(std::string request) {
    
    for (int i = 0; i <= 100; i++) {
        receiveData(request + " " + std::to_string(i) + "%");
    }
    
    finishLoading();
}


