//
//  BlockDownloader.cpp
//  Blocks
//
//  Created by Alexander Blokhin on 20.05.16.
//  Copyright © 2016 Alexander Blokhin. All rights reserved.
//

#include "BlockDownloader.hpp"


BlockDownloader BlockDownloader::downloadDataWithRequest(std::string request, CompletionBlock completion) {
    return BlockDownloader(request, completion);
}

BlockDownloader::BlockDownloader(std::string request, CompletionBlock completion) {

    connection = new BlockConnection();
    
    connection->didFailWithError(^(char *error) {
        completion(nullptr, error);
    });
    
    connection->didReceiveData(^(std::string data) {
        downloadedData.append(data);
        downloadedData.append("\n");
    });
    
    connection->didFinishLoading(^{
        completion(downloadedData, nullptr);
    });
    
    connection->makeRequest(request);
}
