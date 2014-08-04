//
//  BCLocation.h
//  BeeCloud SDK
//
//  Created by Junxian Huang on 2/19/14.
//  Copyright (c) 2014 BeeCloud Inc. All rights reserved.
//

#import <CoreLocation/CoreLocation.h>

/**
 *  A class to represent a location in the map with latitude and longitude.
 */
@interface BCLocation : NSObject

/**
 *  Latitude of the location in degrees in range (-90.0, 90.0). Positive numbers for North.
 */
@property (nonatomic) double latitude;

/**
 *  Longitude of the location in degrees in range (-180.0, 180.0). Positive numbers for East.
 */
@property (nonatomic) double longitude;

/**
 *  Create a new BCLocation object with both latitude and longitude set to 0.0.
 *
 *  @return Returns a new BCLocation.
 */
+ (BCLocation *)location;

/**
 *  Creates a new BCLocation object with the given latitude and longitude.
 *
 *  @param latitude Latitude of the location in degrees.
 *  @param longitude Longitude of the location in degrees.
 *
 *  @return New location object with the given latitude and longitude.
 */
+ (BCLocation *)locationWithLatitude:(double)latitude longitude:(double)longitude;

/**
 *  Get distance in meters from this location to the given location.
 *
 *  @param location Location of the other point.
 *
 *  @return Distance in meters.
 */
- (CLLocationDistance)distanceInMetersTo:(BCLocation*)location;

/**
 *  Convert this location to string representation of "latitude,longitude".
 *
 *  @return String representation of this location.
 */
- (NSString *)toString;

@end
