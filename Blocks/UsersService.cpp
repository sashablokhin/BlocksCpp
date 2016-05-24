//
//  UsersService.cpp
//  Blocks
//
//  Created by Alexander Blokhin on 19.05.16.
//  Copyright © 2016 Alexander Blokhin. All rights reserved.
//

#include "UsersService.hpp"

UsersService UsersService::userStatusChanged(UsersCompletionBlock completion) {
    return UsersService(completion);
}

UsersService::UsersService(UsersCompletionBlock completion) {
    
    this->completion = completion;
    
    connection = new Connection();
    connection->delegate = this;
    
    connection->makeRequest("usersState");
}

void UsersService::connectionDidFailWithError(Connection *connection, char *error) {
    completion(nullptr);
    completion = nullptr;
}

void UsersService::connectionDidReceiveData(Connection *connection, std::string data) {
    downloadedData.append(data);
    downloadedData.append("\n");
}

void UsersService::connectionDidFinishLoading(Connection *connection) {
    completion(downloadedData);
    completion = nullptr;
}

