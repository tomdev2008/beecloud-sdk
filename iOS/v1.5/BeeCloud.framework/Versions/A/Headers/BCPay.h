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
 *  BCPay framework provides handy APIs for in-app purchase, and other payment options to come.
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
 *  @param productIds All products app may use.
 *  @param block      The block could be nil for just keep the products in @products, or you can do some init job for
 *                    in-app store init in the block.
 */
- (void)initProducts:(NSArray *)productIds withBlock:(BCProductBlock)block;

/**
 *  Set the appUserName, this would help to Detecting Irregular Activity.
 *
 *  @param userName Application user name, username in your account system, should be unique for each user.
 */
- (void)setUserName:(NSString *)userName;

/**
 *  Purchase a product.
 *
 *  @param product Product need to purchase.
 *  @param block   Block deal with the purchase result, this should not be null. Notice that if user buy a product
 *                 twice, and the first transaction is not finished, the second one will be ignored.
 */
- (void)purchase:(SKProduct *)product withBlock:(BCPurchaseBlock)block;

/**
 *  Purchase a product.
 *
 *  @param productId productId need to purchase.
 *  @param block     block deal with the purchase result, this should not be null. Remind if user buy a product twice,
 *                   and the first transaction is not finished, the second one will be ignored.
 */
- (void)purchaseWithId:(NSString *)productId withBlock:(BCPurchaseBlock)block;

/**
 *  Restore, for each transaction restored, if transaction.productId in productIds, 
 *  do @BCPurchaseBlock(productId, stateRestored, nil).
 *
 *  @param productIds Products need to be restored.
 *  @param block      Block to deal with the restore callback.
 */
- (void)restore:(NSArray *)productIds withBlock:(BCPurchaseBlock)block;

/**
 *  Delegate method in SKProductsRequestDelegate for requestion products.
 *
 *  @param request  Request for retrieving product info.
 *  @param response Response of this request.
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
 *  @param productId Product ID.
 *
 *  @return Product entity.
 */
- (SKProduct *)getProductById:(NSString *)productId;

@end
