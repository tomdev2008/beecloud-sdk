//
//  BCPay.h
//  BeeCloud
//
//  Created by 健峰 高 on 14-7-29.
//  Copyright (c) 2014年 BeeCloud Inc. All rights reserved.
//

#import <StoreKit/StoreKit.h>

#import "BCConstants.h"

/**
 *  <#Description#>
 */
@interface BCPay : NSObject<SKProductsRequestDelegate>

/**
 *  The product list obtained from app store, initiated by initProducts.
 */
@property (nonatomic, strong) NSArray *products;

/**
 *  Failed init productIds.
 */
@property (nonatomic, strong) NSArray *failedIds;

/**
 *  Get instance of BCPay.
 *
 *  @return instance of BCPay.
 */
+ (instancetype)sharedInstance;

/**
 *  Init products.
 *
 *  @param productIds all products app may use.
 *  @param block the block could be nil for just keep the products in @products,
    or you can do some init job for in-app store init in the block.
 */
- (void)initProducts:(NSArray *)productIds withBlock:(BCProductBlock)block;

/**
 *  Set the appUserName, this would help to Detecting Irregular Activity.
 *
 *  @param userName application user name, username in your account system, should
    be unique for each user.
 */
- (void)setUserName:(NSString *)userName;

/**
 *  Purchase a product.
 *
 *  @param product product need to purchase.
 *  @param block   block deal with the purchase result, this should not be null.
    Remind if user buy a product twice, and the first transaction is not finished,
    the second one will be ignored.
 */
- (void)purchase:(SKProduct *)product withBlock:(BCPurchaseBlock)block;

/**
 *  Purchase a product.
 *
 *  @param productId productId need to purchase.
 *  @param block   block deal with the purchase result, this should not be null.
 Remind if user buy a product twice, and the first transaction is not finished,
 the second one will be ignored.
 */
- (void)purchaseWithId:(NSString *)productId withBlock:(BCPurchaseBlock)block;

/**
 *  Restore, for each transaction restored, if transaction.productId in productIds,
    do @BCPurchaseBlock(productId, stateRestored, nil).
 *
 *  @param productIds products need to be restored
 *  @param block      block deal with the restore callback
 */
- (void)restore:(NSArray *)productIds withBlock:(BCPurchaseBlock)block;

/**
 *  Delegate method in SKProductsRequestDelegate for requestion products.
 *
 *  @param request  request for retrieving product info.
 *  @param response response of this request.
 */
- (void)productsRequest:(SKProductsRequest *)request didReceiveResponse:(SKProductsResponse *)response;

/**
 *  Init product list error delegate.
 *
 *  @param request Init product request
 *  @param error   error
 */
- (void)request:(SKRequest *)request didFailWithError:(NSError *)error;
/**
 *  A method to get a product entity by productId
 *
 *  @param productId
 *
 *  @return product entity
 */
- (SKProduct *)getProductById:(NSString *)productId;

@end
