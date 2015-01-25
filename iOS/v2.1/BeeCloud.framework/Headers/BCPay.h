//
//  BCPay.h
//  BeeCloud
//
//  Created by 健峰 高 on 14-7-29.
//  Copyright (c) 2014年 BeeCloud Inc. All rights reserved.
//

#import <StoreKit/StoreKit.h>

#import "BCConstants.h"
#import "BCObject.h"

/**
 *  BCPay framework provides handy APIs for in-app purchase, WeChat payment. Alipay, and other payment options to come.
 */
@interface BCPay : BCObject<SKProductsRequestDelegate>

#pragma mark - Properties
/**
 *  The product list obtained from app store, initiated by initProducts.
 */
@property (nonatomic, strong) NSArray *products;

/**
 *  Failed init productIds.
 */
@property (nonatomic, strong) NSArray *failedIds;

#pragma mark - Create instances
/** @name Create New Object */

/**
 *  Get instance of BCPay.
 *
 *  @return instance of BCPay.
 */
+ (instancetype)sharedInstance;

#pragma mark - In-App-Purchase functions
/** @name IAP Get products list,purchase product,restore product*/
 
/**
 *  check whether this device is able or allowed to make payments
 *
 *  @return NO if this device is not able or allowed to make payments
 */
- (BOOL)canMakePay;

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
 *  Restore, for each transaction restored, if transaction.productId in productIds, 
 *  do @BCPurchaseBlock(productId, stateRestored, nil).
 *
 *  @param productIds Products need to be restored.
 *  @param block      Block to deal with the restore callback.
 */
- (void)restore:(NSArray *)productIds withBlock:(BCPurchaseBlock)block;

/**
 *  A method to get a product entity by productId
 *
 *  @param productId Product ID.
 *
 *  @return Product entity.
 */
- (SKProduct *)getProductById:(NSString *)productId;

#pragma mark - WXPay functions
/** @name WeChatPay Functions*/

/**
 * 处理微信通过URL启动App时传递的数据
 *
 * @param 需要在 application:openURL:sourceApplication:annotation:或者application:handleOpenURL中调用。
 * @param url 微信启动第三方应用时传递过来的URL
 * @param block  支付结果回调 Block，保证跳转支付过程中，当app被kill掉时，能通过这个接口得到支付结果
 * @return 成功返回YES，失败返回NO。
 */
+ (BOOL)handleOpenUrl:(NSURL *)url withBlock:(BCPayBlock)block;

/**
 *  微信支付调用接口.初始化wx_boby,wx_totalFee,wx_outTradeNo,wx_traceid后调用此接口发起微信支付，并跳转到微信。
 *
 *  @param wx_body       商品描述
 *  @param wx_totalFee   支付金额
 *  @param wx_outTradeNo 商户自定义订单号
 *  @param wx_traceId    支付用户ID，必须保证在商户系统中唯一
 *  @param block         支付结果回调
 */
+ (void)reqWXPayment:(NSString *)wx_body totalFee:(NSString *)wx_totalFee outTradeNo:(NSString *)wx_outTradeNo traceID:(NSString *)wx_traceId payBlock:(BCPayBlock)block;

/**
 *  query orders of the traceID.
 *
 *  @param traceID 支付用户ID,必须保证在商户系统中唯一,商家对用户的唯一标识.
 *
 *  @return order list
 */
+ (NSArray *)queryWXPayOrderByTraceID:(NSString *)wx_traceID;

/**
 *  根据商家提供的订单号，查询该订单状态是否支持退款。如果支持退款，返回可退款金额(以分为单位)；如果不支持退款，返回不支持退款原因。
 *
 *  @param wx_outTradeNo 商家自定义订单号
 *  @param block         接受查询结果；如果改订单支持退款strMsg=@"可退款金额"，否则strMsg=@"不可退款原因"；error可能不为nil,用户自行判断。
 *
 *  @return 如果支持退款返回可退款金额; 不可退款返回nil.
 */
+ (NSString *)canRefundForWeChatPay:(NSString *)wx_outTradeNo payBlock:(BCPayBlock)block;

/**
 *  根据out_trade_no，out_refund_no, refundReason,refundFee查询订单是否可退款，允许退款情况下自动生成预退款订单，否则返回不可退款原因。如果用户欲退款金额大于该订单可退款金额，在block的strMsg中返回错误信息。预退款订单生成成功后，在BeeCloud商户后台对预退款订单进行处理。
 *
 *  @param wx_outTradeNo   商户自定义支付订单号
 *  @param wx_outRefundNo  商户自定义退款订单号
 *  @param wx_refundReason 用户退款理由
 *  @param wx_refundFee    用户欲退款金额
 *  @param block           退款结果回调.如果预退款成功,strMsg=“success”;失败strMsg=@"fail".
 */
+ (void)reqWXRefund:(NSString *)wx_outTradeNo outRefundNo:(NSString *)wx_outRefundNo refundReason:(NSString *)wx_refundReason refundFee:(NSString *)wx_refundFee payBlock:(BCPayBlock)block;

@end
