//
//  UsersService.hpp
//  Blocks
//
//  Created by Alexander Blokhin on 19.05.16.
//  Copyright © 2016 Alexander Blokhin. All rights reserved.
//

#ifndef UsersService_hpp
#define UsersService_hpp

#include <stdio.h>
#include <iostream>
#include "Connection.hpp"

typedef void (^UsersCompletionBlock)(std::string user);

class UsersService: public ConnectionDelegate {
public:
    static UsersService userStatusChanged(UsersCompletionBlock completion);
    
    UsersCompletionBlock completion;
    
    std::string downloadedData;
    
    void connectionDidFailWithError(Connection *connection, char *error);
    void connectionDidReceiveData(Connection *connection, std::string data);
    void connectionDidFinishLoading(Connection *connection);
    
private:
    UsersService(UsersCompletionBlock completion);
    Connection *connection;
};


#endif /* UsersService_hpp */
