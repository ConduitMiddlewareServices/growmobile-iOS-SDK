//
//  TouchbeamManagerDelegate.h
//
//  Created by tal shahar on 12/3/14.
//  Copyright (c) 2014 tal shahar. All rights reserved.
//

typedef enum : NSUInteger {
    InAppMessageDismissedTimeout,
    InAppMessageDismissedUserInteraction,
    InAppMessageDismissedByEvent
} InAppMessageDismissReason;

@protocol TouchbeamDelegate <NSObject>

@optional

//implement this to be notified of incoming push notifications or external in app messages (an external in app message is an in app message that is not drawn by touchbeam)
- (void)didReceiveTouchbeamMessageWithPayload:(NSDictionary*)payload;

//async report of the result of the SDK initialization
- (void)didFinishInitializationWithResult:(BOOL)success;

//async report of the result of email registration
- (void)didFinishEmailRegistrationWithResult:(BOOL)success;

//implement this to be notified when the SDK delete an in app message from the inbox to make room for a new one
- (void)didRemoveInboxMessage:(NSString*)messageId;


@end

