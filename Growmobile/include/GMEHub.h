//
//  GMEHub.h
//
//  Created by tal shahar on 10/26/14.
//  Copyright (c) 2014 tal shahar. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GMEConstants.h"
#import "GMEHubDelegate.h"

typedef enum : NSUInteger {
    GME_Success,
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
- (void)registerEmail:(NSString*)emailAddress;
//use this method to set the default font for in app messages text (title, body and buttons)
- (void)setFont:(NSString*)font;
//for sending a custom event through the SDK
- (GME_Result)reportCustomEvent:(GMECustomEvent*)event;

//for sending an in app purchase event
- (GME_Result)reportInAppPurchaseEvent:(GMEInAppPurchaseEvent*)event;

//request  to display an in app message with a given id
- (GME_Result)showMessage:(NSString*)messageId;

//returns GME sdk version
- (NSString*)sdkVersion;

//return Apple Push Notification Services token
- (NSString*)apnsToken;

//the following 2 methods need not be called unless the sdk is being hosted by an iOS extension, such as a keyboard. otherwise they are handled automatically by the SDK

//called to report app coming into foreground
- (void)foregroundEvent;

//called to report app sent to backgroud
- (void)backgroundEvent;

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


@end




