//
//  TouchBeamManager.h
//  TouchBeamTestApp
//
//  Created by tal shahar on 10/26/14.
//  Copyright (c) 2014 tal shahar. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TouchBeamConstants.h"
#import "TouchbeamDelegate.h"

typedef enum : NSUInteger {
    TB_Success,
    TB_IntializationInProgress, //returned by the startup method if initialization process is currently in progress
    TB_ErrorNotInitialized, //returned by various methods when trying to use the sdk without first initializing it
    TB_EventStored, //internal return value
    TB_EventStoreFlushed, //internal return value
    TB_EventError,
    TB_MissingEventName, //returned by reportCustomEvent and reportInAppPurchaseEvent when an event name is not set
    TB_InvalidTouchbeamKey, //returned by the startup method if the api key input param is not valid
    TB_EmptyTouchbeamKey, //returned by the startup method if the api key input param is empty
    TB_MessageNotFound //returned by showMessage when the messageId input param does not correspond to a valid inbox message
} TB_Result;

//cr: things that are not called by the developer should not be exposed


@interface TouchbeamCustomEvent : NSObject

@property NSString* eventName;
@property NSString* eventTypeName;
@property NSString* valueName;
@property NSString* valueUnit;
@property NSString* textValue;
@property double numericValue;
@property NSDictionary* attributes;

@end

@interface TouchbeamInAppPurchaseEvent : NSObject

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


//this singleton is the main interface into the touch beam sdk

@interface Touchbeam : NSObject
@property (nonatomic,weak) id<TouchbeamDelegate> delegate;

+ (Touchbeam *)sharedManager;

//cr: figure out a way to hide form the developer methods he is not supposed to call
////////////////////////////////////////////////
//for external use by the integrator of the SDK
////////////////////////////////////////////////

//required to cal once to start up the touch beam manager shared instance
- (TB_Result)startup:(NSString*)apiKey;

- (void)setCustomerUserId:(NSString*)userId;
- (void)setCustomerDeviceId:(NSString*)deviceId;
- (void)setApplicationVersionType:(NSString*)type;

- (void)registerEmail:(NSString*)emailAddress;

//for sending a custom event through the SDK
- (TB_Result)reportCustomEvent:(TouchbeamCustomEvent*)event;

//for sending an in app purchase event
- (TB_Result)reportInAppPurchaseEvent:(TouchbeamInAppPurchaseEvent*)event;

//request touchbeam to display an in app message with a given id
- (TB_Result)showMessage:(NSString*)messageId;

//returns touchbeam sdk version
- (NSString*)sdkVersion;

//returns the current touchbeam device id
- (NSString*)deviceId;

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




