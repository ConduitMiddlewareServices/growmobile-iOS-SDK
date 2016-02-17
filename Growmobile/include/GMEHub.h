//
//  GMEHub.h
//
// Created by Growmobile
//  Copyright (c) 2016 Growmobile. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GMEConstants.h"
#import "GMEHubDelegate.h"

typedef enum : NSUInteger {
    GME_Success,
    GME_Error, //General error
    GME_ErrorNoCustomerUserId, //returned by setUserData:data if customer user id is not set
    GME_IntializationInProgress, //returned by the startup method if initialization process is currently in progress
    GME_ErrorNotInitialized, //returned by various methods when trying to use the sdk without first initializing it
    GME_EventStored, //internal return value
    GME_EventStoreFlushed, //internal return value
    GME_EventError,
    GME_MissingEventName, //returned by reportCustomEvent and reportInAppPurchaseEvent when an event name is not set
    GME_InvalidGMEKey, //returned by the startup method if the api key input param is not valid
    GME_EmptyGMEKey, //returned by the startup method if the api key input param is empty
    GME_MessageNotFound //returned by showMessage when the messageId input param does not correspond to a valid inbox message
} GME_Result;

//cr: things that are not called by the developer should not be exposed


@interface GMECustomEvent : NSObject

@property NSString* eventName;
@property NSString* eventTypeName;
@property NSString* valueName;
@property NSString* valueUnit;
@property NSString* textValue;
@property double numericValue;
@property NSDictionary* attributes;

@end

@interface GMEInAppPurchaseEvent : NSObject

@property NSString* eventName;
@property NSString* eventTypeName;
@property NSString* valueName;
@property NSString* valueUnit;
@property NSString* textValue;
@property NSDictionary* attributes;
@property NSString* basketId;
@property NSInteger itemQuantity;
@property double itemPrice;
@property NSString* incentiveId;

@end


//this singleton is the main interface into the GME sdk

@interface GMEHub : NSObject
@property (nonatomic,weak) id<GMEHubDelegate> delegate;

+ (GMEHub *)sharedHub;

//cr: figure out a way to hide form the developer methods he is not supposed to call
////////////////////////////////////////////////
//for external use by the integrator of the SDK
////////////////////////////////////////////////

//required to cal once to start up the GMEHub shared instance
- (GME_Result)startup:(NSString*)apiKey;

//optional
- (void)setCustomerUserId:(NSString*)userId;
- (void)setCustomerDeviceId:(NSString*)deviceId;
- (void)setApplicationVersionType:(NSString*)type;
- (void)setIDFA:(NSString*)idfa;
//use this method to set the default font for in app messages text (title, body and buttons)
- (void)setFont:(NSString*)font;
//for sending a custom event through the SDK
- (GME_Result)reportCustomEvent:(GMECustomEvent*)event;
//for sending any additional data related to this user
- (GME_Result)setUserData:(NSDictionary*)data;

//for sending an in app purchase event
- (GME_Result)reportInAppPurchaseEvent:(GMEInAppPurchaseEvent*)event;

//request  to display an in app message with a given id
- (GME_Result)showMessage:(NSString*)messageId;

//returns GME sdk version
- (NSString*)sdkVersion;

//return Apple Push Notification Service token
- (NSString*)apnsToken;

//adsmart
- (NSDictionary*)shouldShowAd:(NSString*)placement adTypes:(NSArray*)adTypes;
- (GME_Result)setAdSmartsLogic:(NSDictionary*)logic;
- (void)reportAdImpressionEventWithPlacement:(NSString*)placement andAdType:(NSString*)ad_type;
- (BOOL)isAdSmartsLogicExist;

/*
 -- LIFECYCLE EVENTS
 -- These APIs will be called by your AppDelegate incase you did not use the GME Auto Setup
 */

//called to report app coming into foreground
- (void)foregroundEvent;

//called to report app sent to backgroud
- (void)backgroundEvent;

//
-(void)applicationWillResignActive;
-(void)applicationWillTerminate;
-(void)applicationDidEnterBackground;
////////////////////////////////////////////////
//for internal use - called only from within the SDK
////////////////////////////////////////////////

//called to report app launch
- (void)launchEvent;

//called to report app has been terminated
- (void)terminateEvent;

//called when a push token is received
- (void)pushTokenReceived:(NSData*)token;

//called
- (void)pushNotificationReceived:(NSDictionary*)userInfo;

//clears experiment, variant and campaign ids
- (void)clearPushParams;

- (NSTimeInterval)currentSessionDuration;


@end




