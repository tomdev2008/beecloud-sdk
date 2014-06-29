//
//  BCUtil.h
//  BeeCloud SDK
//
//  Created by Junxian Huang on 2/17/14.
//  Copyright (c) 2014 BeeCloud Inc. All rights reserved.
//

#import "BCConstants.h"

/**
 *  This is a utility class, which provides useful functions for developers to write code using BeeCloud.
 */
@interface BCUtil : NSObject

/**
*  Generate a random UUID in the format of "550e8400-e29b-41d4-a716-446655440000", in lower case.
*
*  @return The generated UUID string in lower case.
*/
+ (NSString *)generateRandomUUID;

/**
 *  Convert int64 (long long) value of millisecond to NSDate.
 *
 *  @param millisecond Millisecond in int64 (long long).
 *
 *  @return NSDate object converted to.
 */
+ (NSDate *)millisecondToDate:(long long)millisecond;

/**
 *  Convert NSDate to int64 (long long) for the value of millisecond.
 *
 *  @param date NSDate object to be converted.
 *
 *  @return Number of milliseconds in the format of 1400000000000.
 */
+ (long long)dateToMillisecond:(NSDate *)date;

/**
 *  Converts a string in the format of "2014-02-25 14:27:44.037 GMT-08:00" to NSDate.
 *
 *  @param string The date string with format defined in kBCDateFormat.
 *
 *  @return NSDate object converted to.
 */
+ (NSDate *)stringToDate:(NSString *)string;

/**
 *  Converts a NSDate to a string in the format of "2014-02-25 14:27:44.037 GMT-08:00".
 *
 *  @param date NSDate object to be converted.
 *
 *  @return The date string with format defined in kBCDateFormat.
 */
+ (NSString *)dateToString:(NSDate *)date;

/**
 *  Check whether a unichar is a letter 'a' to 'z' or 'A' to 'Z'.
 *
 *  @param ch Character of type unichar to be checked.
 *
 *  @return YES if it is a letter; NO otherwise.
 */
+ (BOOL)isLetter:(unichar)ch;

/**
 *  Check whether a unichar is a digit '0' to '9'.
 *
 *  @param ch Character of type unichar to be checked.
 *
 *  @return YES if is a digit; NO otherwise.
 */
+ (BOOL)isDigit:(unichar)ch;

/**
 *  Check the validness of an identifier. A valid identifier is a letter followed by any sequence of letters, digits, or
 *  the underscore (_). The identifier ending with two underscores, such as "class__" are reserved for internal uses and
 *  are not permitted.
 *
 *  @param str String identifier to be checked.
 *
 *  @return YES if it is an valid identifier; NO otherwise, such as str == nil, "chass__", "1table", etc.
 */
+ (BOOL)isValidIdentifier:(NSString *)str;

/**
 *  Check the validness of a UUID string, which should be in the format of "550e8400-e29b-41d4-a716-446655440000".
 *
 *  @param uuid uuid to be check.
 *
 *  @return YES if uuid format is valid, or NO if format is invalid or when uuid is nil.
 */
+ (BOOL)isValidUUID:(NSString *)uuid;

@end
