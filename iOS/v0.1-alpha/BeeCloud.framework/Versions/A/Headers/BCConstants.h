//
//  BCConstants.h
//  BeeCloud SDK
//
//  Created by Junxian Huang on 2/18/14.
//  Copyright (c) 2014 BeeCloud Inc. All rights reserved.
//

#ifndef BeeCloud_BCConstants_h
#define BeeCloud_BCConstants_h

/**
 *  BeeCloud SDK release version.
 */
static NSString * const kBeeCloudVersion = @"0.1-alpha";

/**
 *  Supported data types for BCObject.
 *
 *  Make sure to use the corresponding Objective-C types following the BCDataType.
 */
typedef NS_ENUM(NSInteger, BCDataType) {
    /**
     *  bool type. When in the object format, it corresponds to [NSNumber numberWithBool:].
     */
    BCDataTypeBool,
    /**
     *  int32 type. When in the object format, it corresponds to [NSNumber numberWithInt:].
     */
    BCDataTypeInt32,
    /**
     *  int64 type. When in the object format, it corresponds to [NSNumber numberWithLongLong:].
     */
    BCDataTypeInt64,
    /**
     *  float type. When in the object format, it corresponds to [NSNumber numberWithFloat:].
     */
    BCDataTypeFloat,
    /**
     *  double type. When in the object format, it corresponds to [NSNumber numberWithDouble:].
     */
    BCDataTypeDouble,
    /**
     *  string type. It corresponds to NSString.
     */
    BCDataTypeString,
    /**
     *  UUID type. It corresponds to NSString.
     *  Although in the client side, we do not distinguish UUID type from NSString, in the cloud, we store UUID as an
     *  array of bytes in its original form, providing high efficiency for storage and read/write access.
     */
    BCDataTypeUUID,
    /**
     *  date type. It corresponds to NSDate.
     */
    BCDataTypeDate,
    /**
     *  array type. It corresponds to NSArray.
     */
    BCDataTypeArray,
    /**
     *  set type. It corresponds to NSSet.
     */
    BCDataTypeSet,
    /**
     *  map type. It corresponds to NSDictionary.
     */
    BCDataTypeMap,
    /**
     *  NULL type. It corresponds to nil.
     */
    BCDataTypeNull,
    /**
     *  Error type indicating that the data type is not yet supported by the cloud.
     */
    BCDataTypeUnsupported
};

/**
 Date format with millisecond accuracy. Example: "2014-02-25 14:27:44.037 GMT-08:00".
 */
static NSString * const kBCDateFormat = @"yyyy-MM-dd HH:mm:ss.SSS ZZZZ";

@class BCObject;

typedef void (^BCBooleanResultBlock)(BOOL succeeded, NSError *error);
typedef void (^BCIntegerResultBlock)(NSInteger number, NSError *error);
typedef void (^BCArrayResultBlock)(NSArray *objects, NSError *error);
typedef void (^BCObjectResultBlock)(BCObject *object, NSError *error);
typedef void (^BCIdResultBlock)(id object, NSError *error);

#endif
