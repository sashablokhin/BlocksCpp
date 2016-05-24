//
//  main.cpp
//  Blocks
//
//  Created by Alexander Blokhin on 19.05.16.
//  Copyright © 2016 Alexander Blokhin. All rights reserved.
//


#include "Downloader.hpp"
#include "UsersService.hpp"

#include "BlockDownloader.hpp"

int main(int argc, const char * argv[]) {
    
    Downloader::downloadDataWithRequest("hello", ^(std::string data, char *error) {
        printf("%s", data.c_str());
    });
    
    
    UsersService::userStatusChanged(^(std::string user) {
        printf("%s", user.c_str());
    });
    
    BlockDownloader::downloadDataWithRequest("hello", ^(std::string data, char *error) {
        printf("%s", data.c_str());
        printf("download complete! \n");
    });
    
    return 0;
}
