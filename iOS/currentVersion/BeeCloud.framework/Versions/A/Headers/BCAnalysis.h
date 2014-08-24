//
//  BCAnalysis.h
//  BeeCloud
//
//  Created by Junxian Huang on 8/18/14.
//  Copyright (c) 2014 BeeCloud Inc. All rights reserved.
//

/**
 *  BCAnalysis framework provides easy ways for app developers to log user behaviors and the results will be analyzed
 *  and presented in BeeCloud website.
 */
@interface BCAnalysis : NSObject

/**
 *  Log app start event. Call this method inside "- (void)applicationDidBecomeActive:(UIApplication *)application" in
 *  the main app delegate.
 *
 *  @param user User ID, or nil if it can not be determined.
 *  @param note Optional note for debugging information, or nil if nothing to specify.
 *
 */
+ (void)logAppStartForUser:(NSString *)user note:(NSString *)note;

/**
 *  Log app end event. Call this method inside "- (void)applicationWillResignActive:(UIApplication *)application" in the
 *  main app delegate.
 *
 *  @param user User ID, or nil if it can not be determined.
 *  @param note Optional note for debugging information, or nil if nothing to specify.
 *
 */
+ (void)logAppEndForUser:(NSString *)user note:(NSString *)note;

/**
 *  Log an event. For the event that user A clicked "like" on image B, the entity is B and event could be "like_image".
 *
 *  @param event  Event name, such as "posting_photo", which should not be nil.
 *  @param user   User ID, or nil if it can not be determined.
 *  @param entity Target entity ID of this event, e.g., the image ID of a user viewing image event, or nil if nothing to
 *                specify.
 *  @param note   Optional note for debugging information, or nil if nothing to specify.
 *
 */
+ (void)logEvent:(NSString *)event user:(NSString *)user entity:(NSString *)entity note:(NSString *)note;

@end
