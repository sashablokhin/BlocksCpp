//
//  Downloader.cpp
//  Blocks
//
//  Created by Alexander Blokhin on 19.05.16.
//  Copyright © 2016 Alexander Blokhin. All rights reserved.
//

#include "Downloader.hpp"


Downloader Downloader::downloadDataWithRequest(std::string request, CompletionBlock completion) {
    return Downloader(request, completion);
}

Downloader::Downloader(std::string request, CompletionBlock completion) {
    
    this->completion = completion;
    
    connection = new Connection();
    connection->delegate = this;
    
    connection->makeRequest(request);
}

void Downloader::connectionDidFailWithError(Connection *connection, char *error) {
    completion(nullptr, error);
    completion = nullptr;
}

void Downloader::connectionDidReceiveData(Connection *connection, std::string data) {
    downloadedData.append(data);
    downloadedData.append("\n");
}

void Downloader::connectionDidFinishLoading(Connection *connection) {
    completion(downloadedData, nullptr);
    completion = nullptr;
}