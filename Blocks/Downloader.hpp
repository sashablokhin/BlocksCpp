//
//  Downloader.hpp
//  Blocks
//
//  Created by Alexander Blokhin on 19.05.16.
//  Copyright © 2016 Alexander Blokhin. All rights reserved.
//

#ifndef Downloader_hpp
#define Downloader_hpp

#include <stdio.h>
#include "Connection.hpp"

typedef void (^CompletionBlock)(std::string, char *error);

class Downloader: public ConnectionDelegate {
public:
    static Downloader downloadDataWithRequest(std::string request, CompletionBlock completion);

    CompletionBlock completion;
    
    std::string downloadedData;
    
    void connectionDidFailWithError(Connection *connection, char *error);
    void connectionDidReceiveData(Connection *connection, std::string data);
    void connectionDidFinishLoading(Connection *connection);
    
private:
    Downloader(std::string request, CompletionBlock completion);
    Connection *connection;
};

#endif /* Downloader_hpp */
