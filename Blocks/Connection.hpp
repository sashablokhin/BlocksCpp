//
//  Connection.hpp
//  Blocks
//
//  Created by Alexander Blokhin on 19.05.16.
//  Copyright © 2016 Alexander Blokhin. All rights reserved.
//

#ifndef Connection_hpp
#define Connection_hpp

#include <stdio.h>
#include <iostream>

class ConnectionDelegate;

class Connection {
public:
    ConnectionDelegate *delegate;
    
    void makeRequest(std::string request);
};


struct ConnectionDelegate {
    virtual void connectionDidFailWithError(Connection *connection, char *error) {};
    virtual void connectionDidReceiveData(Connection *connection, std::string data) {};
    virtual void connectionDidFinishLoading(Connection *connection) {}; 
};

#endif /* Connection_hpp */
