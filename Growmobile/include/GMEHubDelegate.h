//
//  GMEHubDelegate
//
// Created by Growmobile
//  Copyright (c) 2016 Growmobile. All rights reserved.
//

typedef enum : NSUInteger {
    InAppMessageDismissedTimeout,
    InAppMessageDismissedUserInteraction,
    InAppMessageDismissedByEvent
} InAppMessageDismissReason;

@protocol GMEHubDelegate <NSObject>

@optional

//implement this to be notified of incoming push notifications or external in app messages (an external in app message is an in app message that is not drawn by GME)
- (void)didReceiveGMEMessageWithPayload:(NSDictionary*)payload;

//async report of the result of the SDK initialization
- (void)didFinishInitializationWithResult:(BOOL)success;

//implement this to be notified when the SDK delete an in app message from the inbox to make room for a new one
- (void)didRemoveInboxMessage:(NSString*)messageId;


@end

