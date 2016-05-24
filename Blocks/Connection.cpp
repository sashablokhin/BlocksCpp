//
//  Connection.cpp
//  Blocks
//
//  Created by Alexander Blokhin on 19.05.16.
//  Copyright © 2016 Alexander Blokhin. All rights reserved.
//

#include "Connection.hpp"
#include <string.h>

void Connection::makeRequest(std::string request) {
    
    for (int i = 0; i < 100; i++) {
        delegate->connectionDidReceiveData(this, request);
    }
    
    delegate->connectionDidFinishLoading(this);
}

