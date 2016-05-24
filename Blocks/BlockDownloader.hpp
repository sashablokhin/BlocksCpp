//
//  BlockDownloader.hpp
//  Blocks
//
//  Created by Alexander Blokhin on 20.05.16.
//  Copyright © 2016 Alexander Blokhin. All rights reserved.
//

#ifndef BlockDownloader_hpp
#define BlockDownloader_hpp

#include <stdio.h>
#include "BlockConnection.hpp"

typedef void (^CompletionBlock)(std::string, char *error);

class BlockDownloader {
public:
    static BlockDownloader downloadDataWithRequest(std::string request, CompletionBlock completion);
    
    std::string downloadedData;
    
private:
    BlockDownloader(std::string request, CompletionBlock completion);
    BlockConnection *connection;
};

#endif /* BlockDownloader_hpp */
