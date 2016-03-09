//
//  GMEHub.h
//
// Created by Growmobile
//  Copyright (c) 2016 Growmobile. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GMEConstants.h"
#import "GMEHubDelegate.h"

/*********************************************************************************************************/
// Return types
/*********************************************************************************************************/

typedef enum : NSUInteger {
    GME_Success,
    GME_Error, //General error
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

/*********************************************************************************************************/

@interface GMECustomEvent : NSObject

@property NSString* eventName;
@property NSString* eventTypeName;
@property NSString* valueName;
@property NSString* valueUnit;
@property NSString* textValue;
@property double numericValue;
@property NSDictionary* attributes;

@end

/*********************************************************************************************************/

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

/*********************************************************************************************************/
// This singleton is the main interface into the GME sdk
/*********************************************************************************************************/

@interface GMEHub : NSObject
@property (nonatomic,weak) id<GMEHubDelegate> delegate;

+ (GMEHub *)sharedHub;

/*********************************************************************************************************/
// Required to call once to start up the GMEHub shared instance
/*********************************************************************************************************/

- (GME_Result)startup:(NSString*)apiKey;

/*********************************************************************************************************/
// LIFECYCLE EVENTS
// These APIs will be called by your AppDelegate incase you did not use the GME Auto Setup
/*********************************************************************************************************/

- (void)applicationWillEnterForeground;
- (void)applicationWillResignActive;
- (void)applicationWillTerminate;
- (void)applicationDidEnterBackground;
- (void)didRegisterForRemoteNotificationsWithDeviceToken:(NSData*)deviceToken;
- (void)didFailToRegisterForRemoteNotificationsWithError;
- (void)didReceiveRemoteNotification:(NSDictionary *)userInfo;

/*********************************************************************************************************/
// Optional
/*********************************************************************************************************/

- (void)setCustomerUserId:(NSString*)userId;
- (void)setCustomerDeviceId:(NSString*)deviceId;
- (void)setApplicationVersionType:(NSString*)type;
- (void)setIDFA:(NSString*)idfa;

/*********************************************************************************************************/
// Use this method to set the default font for in app messages text (title, body and buttons)
/*********************************************************************************************************/

- (void)setFont:(NSString*)font;

/*********************************************************************************************************/
// Sends any additional data related to this user
/*********************************************************************************************************/

- (GME_Result)setUserData:(NSDictionary*)data;

/*********************************************************************************************************/
// Sends a custom event through the SDK
/*********************************************************************************************************/

- (GME_Result)reportCustomEvent:(GMECustomEvent*)event;

/*********************************************************************************************************/
// Sends an in app purchase event
/*********************************************************************************************************/

- (GME_Result)reportInAppPurchaseEvent:(GMEInAppPurchaseEvent*)event;

/*********************************************************************************************************/
// request to display an in app message with a given id
/*********************************************************************************************************/

- (GME_Result)showMessage:(NSString*)messageId;

/*********************************************************************************************************/
// returns GME sdk version
/*********************************************************************************************************/

- (NSString*)sdkVersion;

/*********************************************************************************************************/
// Returns Apple Push Notification Service token
/*********************************************************************************************************/

- (NSString*)apnsToken;

/*********************************************************************************************************/
// AdSmarts APIs
/*********************************************************************************************************/

- (NSDictionary*)shouldShowAd:(NSString*)placement adTypes:(NSArray*)adTypes;
- (GME_Result)setAdSmartsLogic:(NSDictionary*)logic;
- (void)reportAdImpressionEventWithPlacement:(NSString*)placement andAdType:(NSString*)ad_type;
- (BOOL)isAdSmartsLogicExist;

/*********************************************************************************************************/

- (NSTimeInterval)currentSessionDuration;

/*********************************************************************************************************/

@end




