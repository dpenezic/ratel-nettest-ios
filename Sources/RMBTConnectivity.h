/*********************************************************************************
* Copyright 2013 appscape gmbh
* Copyright 2014-2015 SPECURE GmbH
* 
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
* 
*   http://www.apache.org/licenses/LICENSE-2.0
* 
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*********************************************************************************/

#import <Foundation/Foundation.h>
#import "RMBTNetworkType.h"

typedef struct {
    uint32_t bytesReceived;
    uint32_t bytesSent;
} RMBTConnectivityInterfaceInfo;

@interface RMBTConnectivity : NSObject

@property (nonatomic, readonly) RMBTNetworkType networkType;

// Human readable description of the network type: Wi-Fi, Celullar
@property (nonatomic, readonly) NSString *networkTypeDescription;

// Carrier name for cellular, SSID for Wi-Fi
@property (nonatomic, readonly) NSString *networkName;

// Timestamp at which connectivity was detected
@property (nonatomic, readonly) NSDate *timestamp;

- (instancetype)initWithNetworkType:(RMBTNetworkType)networkType;

- (NSDictionary*)testResultDictionary;

- (BOOL)isEqualToConnectivity:(RMBTConnectivity*)other;

// Gets byte counts from the network interface used for the connectivity.
// Note that the count refers to number of bytes since device boot.
- (RMBTConnectivityInterfaceInfo)getInterfaceInfo;

@end