//
//  BlockConnection.hpp
//  Blocks
//
//  Created by Alexander Blokhin on 20.05.16.
//  Copyright © 2016 Alexander Blokhin. All rights reserved.
//

#ifndef BlockConnection_hpp
#define BlockConnection_hpp

#include <stdio.h>
#include "ConnectionEvents.hpp"


class BlockConnection: public ConnectionEvents {
public:
    void makeRequest(std::string request);
};




#endif /* BlockConnection_hpp */
