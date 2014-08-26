//
//  BeeCloud.h
//  BeeCloud SDK
//
//  Copyright (c) 2014 BeeCloud Inc. All rights reserved.
//

#import "BCAnalysis.h"
#import "BCConfig.h"
#import "BCConstants.h"
#import "BCLocation.h"
#import "BCObject.h"
#import "BCPay.h"
#import "BCQuery.h"
#import "BCUtil.h"

/**
 *  Global configuration and control methods for BeeCloud.
 */
@interface BeeCloud : NSObject

/**
 *  Set the app key obtained after registering this app in BeeCloud website. This must be called before using any
 *  BeeCloud functions.
 *
 *  @param key App Key obtained from BeeCloud website.
 */
+ (void)setAppKey:(NSString *)key;

/**
 *  Set the master key obtained after registering this app in BeeCloud website.
 *
 *  @warning Only set master key for local debugging, never use this function in production code as there is no
 *           permission control for master key.
 *  @param key Master Key obtained from BeeCloud website.
 */
+ (void)setMasterKey:(NSString *)key;

/**
 *  Change the default network timeout in seconds for all network requests.
 *
 *  @param timeout Seconds in double for default network timeout value, such as 3.5.
 */
+ (void)setNetworkTimeout:(NSTimeInterval)timeout;

/**
 *  Clear all cached copies of BCObjects.
 */
+ (void)clearAllCache;

@end
