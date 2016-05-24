//
//  ConnectionEvents.hpp
//  Blocks
//
//  Created by Alexander Blokhin on 20.05.16.
//  Copyright © 2016 Alexander Blokhin. All rights reserved.
//

#ifndef ConnectionEvents_hpp
#define ConnectionEvents_hpp

#include <stdio.h>
#include <iostream>

typedef void (^FailWithError)(char *error);
typedef void (^ReceiveData)(std::string data);
typedef void (^FinishLoading)();

class ConnectionEvents {
public:
    void didFailWithError(FailWithError block);
    void didReceiveData(ReceiveData block);
    void didFinishLoading(FinishLoading block);
    
    FailWithError failWithError;
    ReceiveData receiveData;
    FinishLoading finishLoading;
};

#endif /* ConnectionEvents_hpp */
