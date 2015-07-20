//
//  GMEInAppMessage.h
//
//  Created by tal shahar on 1/15/15.
//  Copyright (c) 2015 tal shahar. All rights reserved.
//

#import <Foundation/Foundation.h>

//this class encapsulates an in app message delivered through GME

@interface GMEInAppMessage : NSObject

@property (nonatomic) NSMutableDictionary* paramDict;
@property NSString* uuid;

//de serialize from a json file
- (instancetype)initWithFile:(NSURL*)fileUrl;

//serialize into a json file
- (void)store:(NSURL*)fileUrl;

//returns a dictionary of parameters that describe an in app message
- (NSDictionary*)getData;

//an optional inbox trigger
- (NSString*)inboxTrigger;

//apearance events - for delayed messages
- (NSArray*)appearanceEvents;

//returns a url string for a portrait background image to an in app message
+ (NSString*)getPortraitBackgroundImageUrl:(NSString*)imageUrl;

//returns a url string for a landscape background image to an in app message
+ (NSString*)getLandscapeBackgroundImageUrl:(NSString*)imageUrl;

//call to report the corresponding in app message has been shown to the user
- (void)reportDisplayed;

//call to report the corresponding in app message has been closed using the X corner button
- (void)reportDismissed;

//call to report the corresponding in app message has been auto dismissed due to timeout expiration
- (void)reportTimedOut;

//call to report the corresponding in app message has been closed due to an event
- (void)reportTriggeredOutByEvent:(NSString*)eventName;

//call to report the corresponding in app message has been closed due to the user having tapped one of the buttons on the message
- (void)reportAction:(NSString*)action;


@end
