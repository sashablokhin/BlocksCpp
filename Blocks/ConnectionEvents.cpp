//
//  ConnectionEvents.cpp
//  Blocks
//
//  Created by Alexander Blokhin on 20.05.16.
//  Copyright © 2016 Alexander Blokhin. All rights reserved.
//

#include "ConnectionEvents.hpp"

void ConnectionEvents::didFailWithError(FailWithError block) {
    failWithError = block;
}

void ConnectionEvents::didReceiveData(ReceiveData block) {
    receiveData = block;
}

void ConnectionEvents::didFinishLoading(FinishLoading block) {
    finishLoading = block;
}